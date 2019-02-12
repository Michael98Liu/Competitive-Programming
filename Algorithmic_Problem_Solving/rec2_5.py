# cross go first
# illigal:
# 1 x win, but n_o >= n_x

# draw:
# n_o + n_x = 9, no winner

def win(board, mark):
    win = True

    for i in range(3):
        win = True
        for j in range(3):
            if board[i][j] != mark:
                win = False
        if win: return True

    for i in range(3):
        win = True
        for j in range(3):
            if board[j][i] != mark:
                win = False
        if win: return True

    if board[0][0] == board[1][1] == board[2][2] == mark:
        return True
    elif board[2][0] == board[1][1] == board[0][2] == mark:
        return True

def double_win(board, mark = 'X'):
    #print(board)
    win = True
    count = 0

    for i in range(3):
        win = True
        for j in range(3):
            if board[i][j] != mark:
                win = False
        if win: count += 1

    for i in range(3):
        win = True
        for j in range(3):
            if board[j][i] != mark:
                win = False
        if win: count += 1

    if board[0][0] == board[1][1] == board[2][2] == mark:
        count += 1
    elif board[2][0] == board[1][1] == board[0][2] == mark:
        count += 1

    if count > 1:
        return True

board = []
for i in range(3):
    board.append(input())

n_x = 0
n_o = 0

for i in board:
    for j in i:
        if j == 'X': n_x += 1
        if j == '0': n_o += 1

if n_o > n_x:
    print('illegal')
elif n_x - n_o > 1:
    print('illegal')
elif win(board, 'X') and win(board, '0'):
    print('illegal')
elif win(board, 'X') and n_o >= n_x:
    print('illegal')
elif win(board, '0') and n_o < n_x:
    print("illegal")
elif double_win(board):
    print('illegal')
elif win(board, 'X') and n_o < n_x:
    print("the first player won")
elif win(board, '0') and n_o == n_x:
    print("the second player won")
elif n_o + n_x == 9:
    print('draw')
elif n_o == n_x:
    print('first')
elif n_o == n_x - 1:
    print('second')
