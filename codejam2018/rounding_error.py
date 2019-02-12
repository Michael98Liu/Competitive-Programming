from decimal import Decimal, ROUND_HALF_UP
import heapq

t = int(input())

for _ in range(t):
    roundup = []
    rounddown = []

    n, l = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]

    for i in range(n):
        our_value = Decimal(i / n)
        output = Decimal(our_value.quantize(Decimal('.01'), rounding=ROUND_HALF_UP))
        if output > our_value:
            heappush(roundup, i)
        else:
            heappush(rounddown, i)

    print(roundup, rounddown)

    for i in c:
        if i in rounddown:
            
