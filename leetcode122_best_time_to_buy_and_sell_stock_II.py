# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
# difficulty: easy
# Attention: should not initialize bought to 0, stock price may be 0

class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # first find the first local minimum
        profit = 0
        if prices:
            bought = -1
            for i in range(0, len(prices) - 1):
                if bought != -1 and prices[i + 1] < prices[i]:
                    profit += (prices[i] - bought)
                    bought = -1
                elif bought == -1 and prices[i+1] > prices[i]:
                    bought = prices[i]
            if bought != -1:
                print(profit)
                profit += (prices[-1] - bought)
            return profit
        else:
            return profit
