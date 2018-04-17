class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        steps = [[0 for i in obstacleGrid[0]] for j in obstacleGrid]

        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                if obstacleGrid[i][j] == 0:
                    if j-1>=0 and i-1>=0:
                        steps[i][j] = steps[i][j-1] + steps[i-1][j]
                    elif j-1 < 0 and i-1 < 0:
                        steps[i][j] = 1
                    elif j-1 < 0:
                        steps[i][j] = steps[i-1][j]
                    elif i-1 < 0:
                        steps[i][j] = steps[i][j-1]
                else:
                    steps[i][j] = 0
        return steps[-1][-1]
        
