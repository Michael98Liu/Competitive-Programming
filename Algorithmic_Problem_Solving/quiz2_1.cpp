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
#define INF 1000000010

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

#define MAXN 100001
int n, dist[MAXN];
struct Pair { // custom pair (vertex, distance) that compares based on distance
  int x, d;
  Pair(int _x, int _d): x(_x), d(_d) {}
  bool operator < (const Pair &ano) const { return d > ano.d; }
};

void dijkstra(graph& g, vi& post) {
  priority_queue<Pair> pq;
  for (int x = 0; x < MAXN; x++) dist[x] = INF;
  EACH(i, post){
      pq.push(Pair(i, 0));
      dist[i] = 0;
  }

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



int main(){
    int n,m,x,y,w,k,a;
    cin >> n >> m;
    //print(n);
    graph g;
    vi offices;
    //print(m);
    FOR(i, 0, m){
        cin >> x >> y >> w;
        g[x][y] = w;
        g[y][x] = w;
    }

    cin >> k;
    FOR(i, 0, k){
        cin >> a;
        offices.pb(a);
    }

    dijkstra(g, offices);

    FOR(i, 1, n+1){
        printf("%d\n", dist[i]);
    }

    return 0;

}
