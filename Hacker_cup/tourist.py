# T cases
# N K V

t = int(input())

for _ in range(t):
    n, k, v = [int(i) for i in input().split()]

    places = {}
    for i in range(n):
        places[input()] = i
    visited_most = k*(v-1) % n

    i = visited_most
    output = []

    print("Case #{}:".format(_+1), end="")

    for count in range(k):
        for name, popularity in places.items():
            if popularity == (i + count)%n:
                output.append(name)
                break

    sorted_out = sorted(output, key=places.get)

    for i in sorted_out:
        print(" {}".format(i), end="")

    print()
