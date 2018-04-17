n, a, b = [int(x) for x in input().split()]
car = input()
total = 0
if a > b:
    c = 0 # should place a
else:
    c = 1 # should place b

for i in range(len(car)):
    if car[i] == '.':
        if a > 0 and b > 0:
            if c:
                b -= 1
                c = 0
            else:
                a -= 1
                c = 1
            total += 1
        else:
            if b > 0:
                if c:
                    b -= 1
                    total += 1
                    c = 0
                else:
                    c = 1
            elif a > 0:
                if c == 0:
                    a -= 1
                    total += 1
                    c = 1
                else:
                    c = 0
            else:
                break
    else:
        c = 0 if a > b else 1

print(total)
