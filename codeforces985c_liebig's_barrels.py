# hint: http://codeforces.com/blog/entry/59623
# choose the maximum index of the stave so that there are at least rg-(n-i) staves left

n, k, l= [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
b.sort()
total = 0

if b[-1] - b[0] <= l:
    rg = n*k # this is important
else:
    for rg in range(n*k):
        if b[rg] -b[0] > l:
            break

if rg < n:
    print(0)
else:
    volume = 0
    stave = 0

    for i in range(n):
        stave = min(i*k, rg-(n-i))
        volume += b[stave]

    print(volume)
