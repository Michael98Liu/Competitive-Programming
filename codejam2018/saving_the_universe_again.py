t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    l = input().split(" ")
    n = int(l[0])
    string = l[1]
    damage = [0]* len(string)
    d = 1
    last_s = 0
    total = 0
    count = 0

    for j in range(len(string)):
        if string[j] == 'S':
            damage[j] = d
            last_s = j
            total += d
        else:
            d *= 2
            damage[j] = 0

    to_update = last_s

    while to_update > 0 and total > n:
        if damage[to_update - 1] != 0: # previous one is also a shoot
            to_update -= 1
            last_s = to_update + 1
        else:
            # previous one is a charge, swap
            temp = damage[to_update - 1]
            damage[to_update - 1] = damage[to_update]
            damage[to_update] = temp
            to_update -= 1
            damage[to_update] /= 2
            count += 1
            total -= damage[to_update]
            if last_s == to_update + 1: # what is swapped is the last shoot
                last_s = to_update
            else: # not the last shoot
                to_update = last_s
                if last_s +1 < len(damage) and damage[last_s + 1] != 0: last_s += 1
        #print(damage, total)


    if total <= n:
        print("Case #{}: {}".format(i, count))
    else:
        print("Case #{}: IMPOSSIBLE".format(i))
