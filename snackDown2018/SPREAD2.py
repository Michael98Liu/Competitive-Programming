t = int(input())

for i in range(t):
    n = int(input())
    l = [int(x) for x in input().split()]

    numKnown = 1
    numInform = l[0]
    day = 0
    #print(l)
    #print("Day {}: {} {}".format(day, numKnown, numInform))

    while numKnown < len(l):
        prevKnown = numKnown
        prevInform = numInform

        numKnown = prevKnown+prevInform
        numInform += sum(l[prevKnown: prevKnown+prevInform])

        day += 1
        #print("Day {}: {} {}".format(day, numKnown, numInform))

    print(day)
