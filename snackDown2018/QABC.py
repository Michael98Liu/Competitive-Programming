t = int(input())

for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    failed = False

    for i in range(len(a)-2):
        if a[i] > b[i]:
            failed = True
            print("NIE")
            break

        diff = b[i] - a[i]

        a[i] += diff
        a[i+1] += 2*diff
        a[i+2] += 3*diff

    if not failed:
        if a[-2] != b[-2] or a[-1] != b[-1]:
            print("NIE")
        else:
            print("TAK")
