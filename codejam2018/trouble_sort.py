from sys import stdin

t = int(input())
for j in range(1, t+1):
    length = int(input())
    takein = stdin.readline()
    array = takein.split(" ")
    odd = [0] * int(length/2)
    even = [0] * int(length/2 + 1) if length % 2 == 1 else [0] * int(length/2)

    for i in range(len(even)):
        if 2*i + 1 < len(array): odd[i] = int(array[2*i+1])
        even[i] = int(array[2*i])

    even.sort()
    odd.sort()

    for i in range(len(odd)):
        array[2*i] = even[i]
        array[2*i + 1]= odd[i]
    if len(odd) != len(even):
        array[-1] = even[-1]

    for i in range(0, len(array) -1):
        if array[i] > array[i+1]:
            print("Case #{}: {}".format(j, i))
            break
    else:
        print("Case #{}: OK".format(j))
