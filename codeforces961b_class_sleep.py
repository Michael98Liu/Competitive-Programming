n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]

total, count = 0, 0
extra = 0

for i in range(n):
    if t[i] == 1:
        total += a[i]

for i in range(n):
    count += 1
    if t[i] == 0:
        extra += a[i]
    if count == k:
        break

largest = extra

for j in range(i + 1, n):
    if t[j-k] == 0:
        extra -= a[j-k]
    if t[j] == 0:
        extra += a[j]
    largest = max(largest, extra)

print(largest + total)
