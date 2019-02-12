# subproblem: find the longest increase subsequence up to n -1 

class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        longest = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    longest[i] = max(longest[i], longest[j] + 1)
        maximum = 0
        #print(longest)
        for i in longest:
            maximum = i if i > maximum else maximum
        return maximum
