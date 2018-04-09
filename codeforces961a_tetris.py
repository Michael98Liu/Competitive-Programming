m, n = [int(x) for x in input().split()]
row = [0]*m

tetris = [int(x) for x in input().split()]
for i in tetris:
    row[i-1] += 1

print(min(row))
