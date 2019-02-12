#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <map>
#include <array>
#include <set>
#include <unordered_set>
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

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

typedef unordered_map<int, int> umi;
typedef unordered_set<int> usi;
typedef unordered_map<int, umi> graph;

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
#define contains(m,x) m.find(x) != m.end()

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

class Node{
public:
    Node* parent;
    int rank;
};

class Edge{
public:
    int x;
    int y;
    int w;

    Edge(int a, int b, int c){
        x = a;
        y = b;
        w = c;
    }

    bool operator < (const Edge &ano) const { return w < ano.w; }
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

ll kruskal(int n, graph& g) {
    vector<Node*> nodes;
    vector<Edge> edges;
    int x, y, w;
    FOR(i, 0, 100001){
        Node* node = new Node();
        nodes.pb(node);
    }
    initUnionFind(nodes); // create a union-find structure for n vertices

    FORIT(it, g){
        x = it->F;
        FORIT(iit, it->S){
            y = iit->F;
            w = iit->S;
            edges.pb(Edge(x, y, w));
        }
    }
    sort(all(edges)); // sort edges by increasing weight
    ll weightMST = 0;

    EACH(e, edges) {
        if (find(nodes[e.x]) != find(nodes[e.y])) {
            weightMST += e.w;
            //print(e.w);
            unionNodes(nodes[e.x], nodes[e.y]);
        }
    }
    return weightMST;
}

int main(){
    int n,m;
    cin >> n >> m;
    int x,y,d;
    graph g;

    FOR(i, 0, m){
        cin >> x >> y >>d;
        g[x][y] = d;
        g[y][x] = d;
    }

    ll ans = kruskal(n, g);

    if ( ans != 0) printf("%lld\n", ans);
    else printf("-1\n" );

    return 0;

}
