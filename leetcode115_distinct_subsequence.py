# https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C++-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)
# even the solution is not easy to understand.
# if s[j] == t[i], why add dp[i][j] and dp[i-1][j-1]: because if those two equal, all the possibilities before it can "live"

class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        dp = [[0 for i in range(len(s)+1)] for i in range(len(t)+1)]
        for i in range(len(dp)):
            for j in range(len(dp[0])):
                if i == 0: dp[i][j] = 1
                elif j == 0: dp[i][j] = 0
                elif t[i-1] == s[j-1]: dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
                else: dp[i][j] = dp[i][j-1]
        return dp[-1][-1]
