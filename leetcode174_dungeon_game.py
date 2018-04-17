class Solution:
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        health = [[0 for i in dungeon[0]] for j in dungeon]
        m = len(dungeon)
        n = len(dungeon[0])

        for i in range(m -1, -1, -1):
            for j in range(n-1, -1, -1):
                if j+1 < n and i+1 < m:
                    health[i][j] = min(health[i][j+1], health[i+1][j]) - dungeon[i][j]
                elif j+1 >= n and i+1 >= m:
                    health[i][j] = 0-dungeon[i][j] + 1
                elif j+1 >= n:
                    health[i][j] = health[i+1][j]-dungeon[i][j]
                elif i+1 >= m:
                    health[i][j] = health[i][j+1]-dungeon[i][j]

                if health[i][j] <= 0:
                    health[i][j] = 1
                #print(health)
        return health[0][0]
