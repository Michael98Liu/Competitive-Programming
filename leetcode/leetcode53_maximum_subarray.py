# https://leetcode.com/problems/maximum-subarray/description/
# https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts
# key: to find the maxsubarray ends at i, need to find the maxSubArray ends at i-1 first

class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*len(nums)
        dp[0] = nums[0]
        maxsum = dp[0]
        for i in range(1, len(nums)):
            if dp[i-1] > 0:
                dp[i] = nums[i] + dp[i-1]
            else:
                dp[i] = nums[i]
            maxsum = dp[i] if maxsum < dp[i] else maxsum

        return maxsum
