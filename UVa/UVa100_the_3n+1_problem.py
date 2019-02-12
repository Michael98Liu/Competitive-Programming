# ways to optimize: store all the intermediate value in recursion

cycle = [0]*1000000

def operation(n):
    if n < 1000000 and cycle[n-1] != 0:
        return cycle[n-1]

    if n == 1:
        return 1
    elif n % 2 == 0:
        ret = operation(int(n/2)) + 1
        if n <= 1000000:
            cycle[n-1] = ret
        return ret
    else:
        ret = operation(int(3*n + 1)) + 1
        if n <= 1000000:
            cycle[n-1] = ret
        return ret

if __name__ == '__main__':
    for i in range(1, 1000000):
        cycle[i-1] = operation(i)
    inp = input()
    while inp != '':
        a, b = [int(x) for x in inp.split()]
        print(a, b, max(cycle[min(a,b)-1:max(a,b)]))

        try:
            inp = input()
        except EOFError:
            break
