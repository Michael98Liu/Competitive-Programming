# solution provided by: @loveWithLegend1, on http://codeforces.com/blog/entry/59105 in comment section
# proof: every consecutive l stones must have been used by all frogs,
# since no frog can jump from stone i to stone i + l directly


import sys

w, l = [int(x) for x in input().split()]
use = [int(x) for x in input().split()]
m = sum(use[0:l])
s = m

for i in range(1, w-l):
    s = s - use[i-1] + use[i+l-1]
    if s < m: m = s

print(m)


'''
import sys

w, l = [int(x) for x in input().split()]
use = [int(x) for x in input().split()]
use.append(sys.maxsize)
count = [0] * (w + 1)
count[0] = 1

for i in range(1, w+1):
    count[i] = min(sum(count[max(i-l,0):i]), use[i-1])

print(count[-1])
'''
