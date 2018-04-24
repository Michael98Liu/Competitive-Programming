# My previous solution is a backtracking solution, which takes exponential time
# Must flag visited vertices, otherwise we would need to try all permutations
# Key to solve the problem: understand the problem: if vertices A dominates B, then B cannot be reached if A is turned off

class Solution:
    def dfs(self, n):
        for i in self.ajl[n]:
            if self.visited[i] == 0:
                self.fromzero[i] = 1
                self.visited[i] = 1
                self.dfs(i)

    def dfsskip(self, s, n):
        self.reachable[s][n] = 1
        for i in self.ajl[n]:
            if i != s: #skip s
                if self.visited[i] == 0:
                    self.visited[i] = 1
                    self.dfsskip(s, i)

    def output(self, n):
        header = "+" + "-"*(2*n-1) + "+"
        print(header)
        for i in range(len(self.fromzero)):
            if self.fromzero[i] == 1:
                print("|Y", end="")
            else:
                print("|N", end='')
        print("|")
        for i in range(1, n):
            print(header)
            if self.fromzero[i] == 1:
                for j in range(n):
                    if self.fromzero[j] ==1 and self.reachable[i][j] == 0:
                        print("|Y", end="")
                    else:
                        print("|N", end="")
                print("|")
            else:
                print("|N" * n + "|")
        print(header)


    def solution(self, t):
        n = int(input())
        self.ajl = []
        self.visited = [0] *n
        self.fromzero = [0] * n
        self.fromzero[0] = 1

        for i in range(n):
            self.ajl.append([])
            row = [int(x) for x in input().split()]
            for j in range(len(row)):
                if row[j] == 1:
                    self.ajl[-1].append(j)

        self.reachable = [[0 for a in range(n)] for b in range(n)]
        self.dfs(0)
        for i in range(len(self.fromzero)):
            if self.fromzero[i] == 1:
                self.visited = [0]*n
                self.dfsskip(i, 0)

        print("Case %d:" %(t+1))
        sol.output(n)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        sol = Solution()
        sol.solution(i)


'''
    def dfs(self, n, path):
        copy = path[:]
        copy[n] = 1
        for i in range(len(path)):
            if copy[i] == 0:
                self.dom[n][i] = 0
            elif self.dom[n][i] == -1:
                self.dom[n][i] = 1
        for i in self.ajl[n]:
            if i != n and copy[i] != 1: #haven't visited
                self.dfs(i, copy)
'''
