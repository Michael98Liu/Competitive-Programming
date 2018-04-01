# https://leetcode.com/problems/climbing-stairs/description/

class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0 or n==1: return 1
        if n == 2: return 2
        climb = [0]*n
        climb[0] = 1
        climb[1] = 2

        for i in range(2, n):
            climb[i] = climb[i-1] + climb[i-2]

        return climb[-1]
