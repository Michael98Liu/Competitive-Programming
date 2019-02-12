t = int(input())

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
productOfTwo = []
sumOfTwo = set()

for i in range(len(primes)):
    for j in range(i+1, len(primes)):
        productOfTwo.append(primes[i]*primes[j])

for i in range(len(productOfTwo)):
    for j in range(i, len(productOfTwo)):
        sumOfTwo.add(productOfTwo[i] + productOfTwo[j])

for i in range(t):
    n = int(input())
    if n in sumOfTwo:
        print("YES")
    else:
        print("NO")
