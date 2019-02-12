# key: find subproblem: mod k of the sum of the subarrays
# use map other wise O(nk)

class Solution:
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if k == 0:
            for i in range(1, len(nums)):
                if nums[i] == 0 and nums[i-1] == 0:
                    return True
            return False
        k = abs(k)
        modsum = {0:-1}
        s = nums[0]
        modsum.update({s%k: 0})
        if len(nums) == 0: return False
        for i in range(1,len(nums)):
            #print(modsum)
            s += nums[i]
            mod = s % k
            if mod not in modsum:
                modsum[mod] = i
            elif i - modsum[mod] > 1:
                return True
            elif nums[i-1] %k == 0 and nums[i]%k == 0:
                return True
            #print(mod)
        return False
