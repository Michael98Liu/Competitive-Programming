n = int(input())
count = 0

# i is the number of degree
for i in range(1, n + 1):
    if n // i >= 2:
        count += 1

print(count + 1)

# alternative: n//2 + 1
