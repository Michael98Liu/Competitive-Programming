t = int(input())

for i in range(t):
    board = []
    n, m = [int(x) for x in input().split()]
    for i in range(n):
        row = input()
        board.append(row)

    dist = dict()

    for i in range(1, n+m-1):
        dist[i] = 0

    for i in range(n):
        for j in range(m):
            if board[i][j] == '1':
                for x in range(n):
                    for y in range(m):
                        if board[x][y] == '1':
                            d = abs(x-i) + abs(y-j)
                            if d != 0:
                                dist[d] += 1

    for k,v in dist.items():
        print("{} ".format(int(v/2)), end="")
    print()
