# https://leetcode.com/problems/jump-game/description/
# Difficulty: medium

class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        i = len(nums) - 1
        while i >= 1:
            j = 1
            while (i - j) >= 0:
                if nums[i - j] >= j:
                    break
                else:
                    j += 1
            # if break, can reach it successfully
            else:
                #print(i,j)
                return False
            i -= j
        if nums and nums[0] != 0: return True
        elif nums[0] == 0 and len(nums) == 1: return True
        else: return False
