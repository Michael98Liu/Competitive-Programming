# careful: last stair is not in the cost list, have to climb to n+1 stair to reach the top

class Solution:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        stair = [0]*(len(cost) + 1)
        for i in range (2, len(cost) + 1):
            stair[i] = min(stair[i-1] + cost[i-1], stair[i-2] + cost[i-2])
        #print(stair)
        return stair[-1]
