n = int(input())
s = set()

a = input().split()

for j in a:
    f = ['0']*26
    for l in j:
        f[ord(l)-97] = '1'
    st = ''.join(f)
    s.add(st)
print(len(s))
