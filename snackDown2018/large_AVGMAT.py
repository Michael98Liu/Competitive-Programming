t = int(input())

for i in range(t):
    board = []
    n, m = [int(x) for x in input().split()]
    for i in range(n):
        row = input()
        board.append(row)

    

    for i in range(m):
        count = 0
        y = i
        x = 0

        while x < n and y >= 0:
            if board[x][y] == '1':
                count += 1
            y -= 1
            x += 1

        housesMinus[i] = count

    for i in range(n):
        count = 0
        x = i
        y = m-1

        while y >=0 and x < n:
            if board[x][y] == '1':
                count += 1
            y -= 1
            x += 1
        housesMinus[m+i-1] = count

    # calculate another diagnal
    for i in range(m):
        count = 0
        y = 0
        x = 0

        while x < n and y >= 0:
            if board[x][y] == '1':
                count += 1
            y += 1
            x += 1

        housesMinus[i] = count

    for i in range(n):
        count = 0
        x = i
        y = m-1

        while y >=0 and x < n:
            if board[x][y] == '1':
                count += 1
            y -= 1
            x += 1
        housesMinus[m+i-1] = count



    print(housesMinus)
