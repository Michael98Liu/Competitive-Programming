def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    odd_sum = 0
    even_sum = 0

    for i in range(n//2):
        odd_sum += abs(a[i] - (i*2 + 1))
        even_sum += abs(a[i] - (i*2 + 2))

    if odd_sum > even_sum:
        print(even_sum)
    else:
        print(odd_sum)

if __name__ == '__main__':
    main()
