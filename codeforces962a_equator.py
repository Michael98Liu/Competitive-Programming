n = int(input())
days = [int(x) for x in input().split()]

s = sum(days)/2
total = 0

for i in range(len(days)):
    total += days[i]
    if total >= s:
        break

print(i+1)
