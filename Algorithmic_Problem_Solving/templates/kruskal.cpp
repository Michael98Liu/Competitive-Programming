int n;
int kruskal() {
    initUnionFind(n); // create a union-find structure for n vertices
    sort(edges); // sort edges by increasing weight
    int weightMST = 0;

    for (e of edges) {
        if (find(e.x) != find(e.y)) {
            weightMST += e.weight;
            unionSets(e.x, e.y);
        }
    }
    return weightMST;
}
