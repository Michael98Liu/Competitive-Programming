a = [int(x) for x in input().split()]
maxeven = 0

for i in range(len(a)):
    maxthis = 0
    b = [0]*14
    for j in range(14):
        b[j] = a[j] + a[i]//14

    b[i] -= a[i]

    for j in range(a[i] % 14):
        b[(i + j + 1) % 14] += 1

    for j in b:
        if j % 2 == 0:
            maxthis += j
    if maxthis > maxeven: maxeven = maxthis
print(maxeven)
