t = int(input())

def main():
    for _ in range(t):
        count = 0
        n = int(input())
        lolli = [1]*n
        seen = [0]*n

        while True:
            a = input()
            if a == '0': print(-1)

            pref = [int(x) for x in input().split()]
            
            d = pref[0]
            if d == -1:
                return

            given = 0

            if d != 0:
                for i in pref[1:]:
                    if seen[i] == 0:
                        seen[i] == 1
                        if lolli[i] == 1:
                            print(i)
                            lolli[i] = 0
                            given = 1

                if not given:
                    for i in pref[1:]:
                        if lolli[i] == 1:
                            print(i)
                            lolli[i] = 0
                        break
                    else:
                        print(-1)
            count += 1
            if count == n:
                break

if __name__ == '__main__':
    main()
