t = int(input())

for _ in range(t):
    n, l = [int(x) for x in input().split()]
    words = ['']*n
    comb = 1
    for i in range(n):
        words[i] = input()

    arr_dic = [ dict() for i in range(l)]

    for i in range(l):
        val = 0
        s = arr_dic[i]
        for j in range(n):
            if words[j][i] not in s:
                s[words[j][i]] = val
                val += 1

        comb *= len(s)
    #print(arr_dic)

    all_poss = [0]*comb

    if n >= comb:
        print("Case #{}: -".format( _ + 1))
    else:
        for i in range(n):
            ind = 0
            c = comb
            for j in range(l):
                c = c/len(arr_dic[j])
                ind += arr_dic[j][words[i][j]] * c
            all_poss[int(ind)] = 1
        str = ''
        #print(all_poss)
        for i in range(comb):
            if all_poss[i] == 0:
                for j in range(len(arr_dic)):
                    if j != len(arr_dic) - 1:
                        ind = i // len(arr_dic[j])
                        i -= ind * len(arr_dic[j])
                    else:
                        ind = i
                    for k, v in arr_dic[j].items():
                        if v == ind:
                            str += k
                break

        print("Case #{}: {}".format(_+1, str))
