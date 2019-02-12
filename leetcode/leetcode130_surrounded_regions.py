# flood fill
# don't know why UFDS solution failed in one test

class Solution:
    def __init__(self):
        self.dr = [0, 0, 1,-1]
        self.dc = [1, -1, 0, 0]

    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board) == 0 or len(board[0]) ==0:
            return
        for i in range(len(board)):
            if board[i][0] == 'O':
                self.bfs(board, i, 0)
            if board[i][-1] == 'O':
                self.bfs(board, i, len(board[i])-1)

        for i in range(len(board[0])):
            if board[0][i] == 'O':
                self.bfs(board, 0, i)
            if board[-1][i] == 'O':
                self.bfs(board, len(board)-1, i)

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '-':
                    board[i][j] = 'O'



    def bfs(self, board, m, n):
        if m == len(board) or n == len(board[0]) or m < 0 or n < 0:
            return
        if board[m][n] =='O':
            board[m][n] = '-'
        else:
            return
        for i in range(4):
            self.bfs(board, m+self.dr[i], n+self.dc[i])





'''
class Solution:

    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m = len(board)
        if m != 0:
            n = len(board[0])
        else:
            n = 0

        self.parent = [-1] * m * n
        toUpdate = [1] * m *n
        for i in range(m*n):
            self.parent[i] = i

        if n > 0:
            for i in range(m):
                if board[i][0] == 'O':
                    toUpdate[i * n] = 0
                if board[i][-1] == 'O':
                    toUpdate[i * n + n - 1] = 0

        for i in range(n):
            if board[0][i] == 'O':
                toUpdate[i] = 0
            if board[-1][i] == 'O':
                toUpdate[n*m - n + i] = 0

        print(toUpdate)

        for i in range(1, m-1):
            for j in range(1, n-1):
                if board[i][j] == 'O':
                    if board[i-1][j] == 'O':
                        if toUpdate[self.parent[(i-1)*n + j]] == 0:
                            self.union((i-1)*n + j, i*n + j)
                        else:
                            self.union(i*n + j, (i-1)*n + j)
                    if board[i+1][j] == 'O':
                        if toUpdate[self.parent[(i+1)*n + j]] == 0:
                            self.union((i+1)*n + j, i*n+j)
                        else:
                            self.union(i*n+j, (i+1)*n + j)
                    if board[i][j-1] == 'O':
                        if toUpdate[self.parent[i*n+j-1]] == 0:
                            self.union(i*n+j-1, i*n+j)
                        else:
                            self.union(i*n+j, i*n+j-1)
                    if board[i][j+1] == 'O':
                        if toUpdate[self.parent[i*n+j+1]] == 0:
                            self.union(i*n+j+1, i*n + j)
                        else:
                            self.union(i*n + j, i*n+j+1)

        print(self.parent)

        for i in range(len(self.parent)):
            if self.parent[self.parent[i]] != self.parent[i]:
                self.parent[i] = self.find(self.parent[i])
        print(self.parent)

        for i in range(m):
            for j in range(n):
                if toUpdate[self.parent[i*n + j]] == 1:
                    board[i][j] = 'X'

    def find(self, a):
        if self.parent[a] != a:
            x = self.find(self.parent[a])
            self.parent[a] = x
            return x
        else:
            return a

    def union(self, a, b):
        #whichever on the border (first parameter) should become the new root
        x = self.find(a)
        y = self.find(b)
        self.parent[y] = x
        self.find(b)
'''
