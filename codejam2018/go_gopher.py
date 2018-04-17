import sys

def grid_is_full(grid):
    for i in grid:
        if i == 0:
            return False
    return True

def solution():
    t = int(input())
    for i in range(t):
        a = int(input())
        m, n = 2,2
        grid = [0] * 9

        while True:
            print("{} {}".format(m, n))
            sys.stdout.flush()
            x, y = [int(s) for s in input().split(" ")]
            if x == -1 and y == -1:
                return
            if x == 0 and y == 0:
                break
            else:
                grid[(1+x-m) * 3 + 1 + y - n] = 1
                if grid_is_full(grid):
                    m += 3
                    grid = [0] * 9
                    if m > 998:
                        m = 2
                        n += 3

solution()
