n, k = [int(x) for x in input().split()]

# furthest place could go: k-1 or n-k

print( min(k - k//(n//k), k-1) + k + 1)
