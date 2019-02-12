from bisect import bisect_left

def takeClosest(myList, myNumber):

    pos = bisect_left(myList, myNumber)
    if pos == 0:
        return myList[0]
    if pos == len(myList):
        return myList[-1]
    before = myList[pos - 1]
    after = myList[pos]
    if after - myNumber < myNumber - before:
       return after
    else:
       return before


count = 0
while True:
    n = int(input())
    if n == 0:
        break
    l = [int(input()) for i in range(n)]

    m = int(input())
    q = [int(input()) for i in range(m)]

    sums = []

    for i in range(n):
        for j in range(i+1, n):
            sums.append(l[i] + l[j])

    sums.sort()

    count +=1
    print("Case {}:".format(count))

    for num in q:
        print("Closest sum to {} is {}.".format(num, takeClosest(sums, num)))
