def find(parent, node):
    # find parent
    if parent[node] == -1:
        return node
    else:
        parent[node] = find(parent, parent[node])
        return parent[node]

def union(parent, x, y):
    #union two sets, parent of y becomes the common parent
    xp = find(parent, x)
    yp = find(parent, y)
    if xp != yp:
        parent[xp] = yp


if __name__ == '__main__':
    n = int(input())
    input()
    result = [0]*n

    for j in range(n):

        node_char = input()
        parent = [-1]*26

        edge = input()
        while edge != "":
            union(parent, ord(edge[0])-65, ord(edge[1]) - 65)
            try:
                edge = input()
            except EOFError:
                break

        count = 0
        for i in parent[:ord(node_char)-64]:
            if i == -1: count += 1

        result[j] = count

    print('\n\n'.join([str(x) for x in result]))
