t = int(input())

for i in range(t):
    n = int(input())

    cards = [int(x) for x in input().split()]

    for j in range(n-1):
        if cards[j+1] < cards[j]:
            break

    else:
        # did not break
        print("YES")
        continue

    if cards[0] < cards[n-1]:
        print("NO")
        continue

    for j in range(j+1, n-1):
        if cards[j+1] < cards[j]:
            print("NO")
            break
    else:
        print("YES")
        continue
