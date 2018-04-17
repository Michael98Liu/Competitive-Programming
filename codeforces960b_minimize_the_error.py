import heapq

n, k, l = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
diff = []
edit = k + l

for i in range(n):
    heapq.heappush(diff, -abs(a[i]-b[i]))

while edit > 0:
    m = heapq.heappop(diff)
    if m < 0:
        m += 1
    else:
        m -=1
    edit -= 1
    heapq.heappush(diff, m)

result = 0
for i in diff:
    result += i*i

print(result)
