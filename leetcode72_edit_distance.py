# when add or delete, no matter corresponding letters are different or not, have to add 1
# when replace, do not add 1 if letters are same

class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if len(word1) != 0 and len(word2) != 0:
            dp = [[0 for i in range(len(word1) +1)] for j in range(len(word2) + 1)]
            for i in range(0, len(word1) + 1):
                dp[0][i] = i
            for j in range(0, len(word2) + 1):
                dp[j][0] = j
            for i in range(1, len(word2) + 1):
                for j in range(1, len(word1) + 1):
                    dp[i][j] = min(dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1) if word2[i-1] != word1[j-1] else min(dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1)
            #print(dp)
            return dp[-1][-1]
        elif len(word1) == 0 and len(word2) == 0:
            return 0
        elif len(word1) == 0:
            return len(word2)
        else:
            return len(word1)
