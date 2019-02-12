def solution():
    string = input()
    numa, numb, numc = 0, 0, 0
    for i in range(len(string)):
        if string[i] == 'a':
            numa += 1
        else:
            break
    for j in range(i, len(string)):
        if string[j] == 'b':
            numb += 1
        elif string[j] == 'a':
            print('NO')
            return
        else:
            break
    for m in range(j, len(string)):
        if string[m] == 'c':
            numc += 1
        elif string[m] == 'a' or string[m] == 'b':
            print('NO')
            return
    if numa == 0 or numb == 0:
        print('NO')
        return
    if numc == numb or numc == numa:
        print('YES')
    else:
        print('NO')

solution()
