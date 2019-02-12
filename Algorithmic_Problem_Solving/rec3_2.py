import operator

mydict = dict()

str = input()

for i in str:
    if i in mydict:
        mydict[i] += 1
    else:
        mydict[i] = 1

sorteddict = sorted(mydict.items(), key=operator.itemgetter(1))

if len(sorteddict) <= 2:
    print(0)
else:
    count = 0
    for i in range(len(sorteddict)-2):
        count += sorteddict[i][1]
    print(count)
