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
#define INF 1e9+1

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

typedef unordered_map<int, int> umi;
typedef unordered_map<int, unordered_map<int, int> > graph;

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

struct Pair { // custom pair (vertex, distance) that compares based on distance
    int x, d;
    Pair(int _x, int _d): x(_x), d(_d) {}
    bool operator < (const Pair &ano) const { return d > ano.d; }
};

void dijkstra(int s, vi& dist, graph& g) {
    priority_queue<Pair> pq;
    pq.push(Pair(s, 0));

    dist[s] = 0;
    while (!pq.empty()) {

        Pair cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.x]) continue; // ignore out-of-date pair
        int x = cur.x;
        FORIT(it, g[x]){
            int y = it->F;
            int w = it->S;
            if (dist[x] + w < dist[y]) {
                dist[y] = dist[x] + w;
                pq.push(Pair(y, dist[y]));
            }
        }
    }
  // dist[x] now stores the weighted SP for every x
}

ll smallest(ll a, ll b, ll c, ll d, ll e){
    return min({a, b, c, d, e});
}


int main(){

    int n,q,m;
    cin >> n >> m;
    int x,y, d;
    graph g;
    vi dist(n+1, INF);
    vi revdist(n+1, INF);
    //vi parent(n+1, 0);

    FOR(i, 0, m){
        cin >> x >> y >> d;
        g[x][y] = d;
        g[y][x] = d;
    }

    dijkstra(1, dist, g);
    dijkstra(n, revdist, g);
    //pv(dist);

    /*
    unordered_set<int> path;
    int pa = parent[n];
    path.insert(n);
    path.insert(pa);

    while( pa != 1 ){
        pa = parent[pa];
        path.insert(pa);
    }
    */

    cin >> q;
    ll d1x, dnx, d1y, dny, d1n, ans;

    FOR(i, 0, q){
        cin >> x >> y >> d;

        d1x = min((ll)dist[x], (ll)dist[y]+d);
        d1y = min((ll)dist[y], (ll)dist[x]+d);
        dny = min((ll)revdist[y], (ll)revdist[x]+d);
        dnx = min((ll)revdist[x], (ll)revdist[y]+d);
        //print(d1x, d1y, dny, dnx);

        ans = smallest(dist[n], d1x + dnx, d1y + dny, d1x + d + dny, d1y + d + dnx);

        printf("%lld\n", ans);
    }

    return 0;

}
