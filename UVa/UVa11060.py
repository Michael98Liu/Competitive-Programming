def find(adjMatrix, deleted):
    # find vertices without incoming edge
    for i in range(0, len(adjMatrix)):
        for j in range(len(adjMatrix)):
            if adjMatrix[j][i] == 1:
                break
        else:
            if deleted[i] == 0:
                deleted[i] = 1
                return i
    return -1

if __name__ == '__main__':
    count = 0
    while True:
        count +=1
        n = int(input())

        drinks = ['']*n
        drinksMap = {}
        deleted = [0] * n
        queue = []
        adjMatrix = [[0 for i in range(n)] for j in range(n)]

        for i in range(n):
            d = input()
            drinks[i] = d
            drinksMap[d] = i

        m = int(input())
        for i in range(m):
            a, b = input().split()
            adjMatrix[drinksMap[a]][drinksMap[b]] = 1

        #print(adjMatrix)
        v = find(adjMatrix, deleted)
        # v is the one without incoming vertices
        queue.append(v)

        sortedDrink = []
        while len(queue):
            v = queue.pop(0)
            sortedDrink.append(v)

            for _ in range(n):
                adjMatrix[v][_] = 0

            while v >= 0:
                v = find(adjMatrix, deleted)
                if v >= 0: queue.append(v)

        print("Case #%d: Dilbert should drink beverages in this order:"%count, end = "")
        for i in sortedDrink:
            print(" ", end='')
            print(drinks[i], end="")
        print(".")
        print()

        try:
            input()
        except EOFError:
            break
