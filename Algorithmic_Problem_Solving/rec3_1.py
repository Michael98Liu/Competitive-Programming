n = int(input())

for i in range(n):
    k = int(input())
    s = set()
    for j in range(k):
        a = input()
        s.add(a)
    print(len(s))
