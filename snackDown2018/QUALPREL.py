t = int(input())

for i in range(t):
    n, k = [int(x) for x in input().split()]
    l = [int(x) for x in input().split()]

    l.sort(reverse=True)

    cutOff = l[k-1]
    result = k

    for j in range(k, n):
        if l[j] == cutOff:
            result += 1
    print("{}".format(result))
