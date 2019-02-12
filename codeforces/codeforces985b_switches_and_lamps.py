n, m = [int(x) for x in input().split()]
a = []
for i in range(n):
    a.append(input())

replacable = [1]*n

for i in range(m):
    count = 0
    ind=0
    for j in range(n):
        if a[j][i] == '1':
            count += 1
            ind = j
    if count == 1:
        replacable[ind] = 0

for i in replacable:
    if i == 1:
        print("YES")
        break
else:
    print("NO")
