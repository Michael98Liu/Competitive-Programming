void computeTreeParents(vector<vi>& parent, vi& treeParent, int n, int logn) {
    //printf("logn %d\n", logn);
    for(int x = 0; x < n; x++) parent[0][x] = treeParent[x];
    //printf("here\n" );
    for(int k = 1; k < logn; k++){
        //printf("%d\n", k);
        for (int x = 0; x < n; x++){
            //printf("x %d\n", x);
            parent[k][x] = parent[k - 1][parent[k - 1][x]];
            //printf("%d\n", parent[k][x]);
        }
    }
}

int getDistUp(vector<vi>& parent, int x, int d, int logn) {
    for (int k = logn - 1; k >= 0; k--)
        if (d & (1<<k)) x = parent[k][x];
    return x;
}

int lca(vector<vi>& parent, vi& depth, int x, int y, int logn) {
    int d = 0, minDepth = min(depth[x], depth[y]);
    // binary search the smallest d so that getDistUp(x, dep[x] - d) == getDistUp(y, dep[y] - d)
    for (int k = logn - 1; k >= 0; k--) {
        int dUp = d + (1 << k);
        if (dUp > minDepth) continue;
        if (getDistUp(parent, x, depth[x] - dUp, logn) == getDistUp(parent, y, depth[y] - dUp, logn)) d = dUp;
    }
    return getDistUp(parent, x, depth[x] - d, logn);
}
