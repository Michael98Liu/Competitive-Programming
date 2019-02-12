#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <unordered_map>
#include <map>
#include <array>
#include <set>
#include <complex>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

#define EPS 1e-14
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INFLL 1e18
#define INF 1e9

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

typedef unordered_map<int, int> umi;
typedef vector<umi> graph;

#define RANGE(i,a,b,d) for (int i=min((int)a,(int)b); i<max((int)a,(int)b); i+=d)
#define RRANGE(i,a,b,d) for (int i=max((int)a,(int)b); i>min((int)a,(int)b); i+=d)
#define FOR(i,a,b) RANGE(i,a,b,1)
#define RFOR(i,a,b) RRANGE(i,a,b,-1)
#define REP(i,s) FOR(i,0,s)
#define RREP(i,s) RFOR(i,s-1,-1)
#define FORIT(it,l) for (auto it = l.begin(); it != l.end(); it++)
#define EACH(x,v) for (auto &x : v)

#define sz(x) (int)(x).size()
#define len(x) (int)sizeof(x)/sizeof(*x)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define contains(m,x) m.find(x) == m.end()

#define pv(v) for(auto &x:v) cout << x << " "; cout << endl;
#define pm(m) for(auto &x:m) cout << x.F << ":" << x.S << " "; cout << endl;
#define pa(a) REP(i, len(a)) cout << a[i] << " "; cout << endl;
#define paa(aa) REP(i, len(aa)) {REP(j, len(aa[0])) cout << aa[i][j] << " "; cout << endl;}

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
void print(T t){
    cout << t << endl;
}

template<typename T, typename... Args>
void print(T t, Args... args){
    cout << t << " ";
    print(args...);
}

void dfs(vi& distance, vi& depth, vi& treeParent, map<int, map<int, int> >& weight, int root){
    vi tovisit;
    tovisit.pb(root);
    distance[root] = 0;
    depth[root] = 0;
    treeParent[root] = -2;

    while( tovisit.size() != 0 ){
        //pv(tovisit);
        root = tovisit.back();
        tovisit.pop_back();

        FORIT(it, weight[root]){
            if( treeParent[it->F] == -1 ){
                tovisit.pb(it->F);
                distance[it->F] = distance[root] + it->S;
                depth[it->F] = depth[root] + 1;
                treeParent[it->F] = root;
                //print(it->F, distance[it->F]);
            }
        }
    }
}

void computeTreeParents(vector<vi>& parent, vi& treeParent, int n, int logn) {
    for(int x = 0; x < n; x++) parent[0][x] = treeParent[x];
    for(int k = 1; k < logn; k++){
        for (int x = 0; x < n; x++){
            parent[k][x] = parent[k - 1][parent[k - 1][x]];
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

int main(){
    int n, q;
    scanf("%d\n", &n);
    int x, y, d, root;
    vi treeParent(n, -1);
    vi distance(n, 0);
    vi depth(n, 0);

    map<int, map<int, int> > weight;

    FOR(i, 0, n-1){
        scanf("%d %d %d\n", &x, &y, &d);

        weight[x-1][y-1] = d;
        weight[y-1][x-1] = d;
    }
    root = x;
    //printf("root %d\n", root);

    dfs(distance, depth, treeParent, weight, root);

    vector<vi> parent;
    int logn = (int)log2(n)+1;
    FOR(i, 0, logn){
        parent.pb(vi(n, 0));
    }

    computeTreeParents(parent, treeParent, n, logn);

    scanf("%d\n", &q);
    int ancester, ans;
    FOR(i, 0, q){
        scanf("%d %d\n", &x, &y);
        ancester = lca(parent, depth, x-1, y-1, logn);
        //printf("ancester %d\n", ancester);
        //printf("distance %d %d %d\n", distance[x-1], distance[y-1], distance[ancester]);
        ans = distance[x-1] + distance[y-1] - 2* distance[ancester];
        printf("%d\n", ans);
    }

    //pv(treeParent);
    //pv(distance);
    //pv(depth);
    return 0;
}
