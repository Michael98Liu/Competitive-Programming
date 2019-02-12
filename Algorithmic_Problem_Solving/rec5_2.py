def combination(chosen, l, count, startInd):
    if count == 6:
        first = True
        for i in range(len(l)):
            if chosen[i] == 1:
                if not first:
                    print(" ", end="")
                print(l[i], end="")
                first = False
        print()
        return

    if startInd == len(l):
        return

    for i in range(startInd, len(l)):
        chosen[i] = 1
        combination(chosen, l, count+1, i+1)
        chosen[i] = 0

count = 0
while True:

    l = [int(x) for x in input().split()]
    n = l[0]
    if n == 0:
        break
    if count != 0:
        print()
    l= l[1:]
    chosen = [0] * len(l)

    combination(chosen, l, 0, 0)
    count += 1
