def sameHand(a, b):
    if a == b:
        return True
    if a == 'd' and b == 'f':
        return True
    if a == 'f' and b == 'd':
        return True
    if a == 'j' and b == 'k':
        return True
    if a == 'k' and b == 'j':
        return True

t = int(input())

for i in range(t):
    n = int(input())
    appear = dict()
    time = 0

    for j in range(n):
        word = input()
        if word in appear:
            time += appear[word]/2
            continue

        else:
            thisTime = 2
            for i in range(1, len(word)):
                if sameHand(word[i], word[i-1]):
                    thisTime += 4
                else:
                    thisTime += 2

            appear[word] = thisTime
            time += thisTime

    print(int(time))
