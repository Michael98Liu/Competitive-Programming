n = int(input())

for i in range(n):
    total = 0
    most = 0
    most_ind = 0
    m = int(input())
    votes = [0]*m
    for j in range(m):
        a = int(input())
        votes[j] = a
        total += a
        if a > most:
            most = a
            most_ind = j + 1
    votes.sort()
    if votes[-1] == votes[-2]:
        print("no winner")
    else:
        if votes[-1] > total/2:
            print("majority winner {}".format(most_ind))
        else:
            print("minority winner {}".format( most_ind))
