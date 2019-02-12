class Node{
public:
    Node* parent;
    int rank;
};

void initUnionFind(vector<Node*>& nodes) {
    EACH(x, nodes) {
        x->parent = x;
        x->rank = 0;
    }
}

Node* find(Node* x) {
    if (x->parent == x) return x;
    return x->parent = find(x->parent); // path compression
}

void unionNodes(Node* x, Node* y) {
    Node* xRoot = find(x), *yRoot = find(y);
    /** start rank optimization **/
    if (xRoot->rank > yRoot->rank)
        swap(xRoot, yRoot);
    if (xRoot->rank == yRoot->rank)
        yRoot->rank += 1;
    /** end rank optimization **/
    xRoot->parent = yRoot;
}
