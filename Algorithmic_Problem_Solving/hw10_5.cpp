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

typedef unordered_map<int, vi> umi;
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

int bellmanford(graph& g, vi& dist, int n, vi& reachable){
    // return 1 if has negative cycle, 0 if not
    dist[1] = 0;
    int x, y, w;
    FOR(i, 0, n-1){ // loop n-1 times
        FOR(j, 1, n+1){
            x = j;
            FORIT(mit, g[j]){
                y = mit->F;
                FORIT(vit, mit->S){
                    w = *vit;
                    if( dist[x] + w < dist[y] ) dist[y] = dist[x] + w;
                }

            }
        }
    }

    FOR(j, 1, n+1){
        x = j;
        FORIT(mit, g[j]){
            y = mit->F;
            FORIT(vit, mit->S){
                w = *vit;
                if( reachable[y] == 1 ){
                    if( dist[x] + w < dist[y] ) return 1;
                }
            }
        }
    }

    return 0;
}

void bfs(graph& g, vi& reachable){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        FORIT(it, g[x]){
            if( reachable[it->F] == 0 ){
                reachable[it->F] = 1;
                q.push(it->F);
            }
        }
    }
}

int main(){
    int n,m,x,y,w;
    scanf("%d %d\n", &n, &m);
    vi dist(n+1, 1e8);
    vi distNeg(n+1, 1e8);
    graph posG;
    graph negG;
    vi reachable(n+1, 0);
    reachable[1] = 1;

    FOR(i, 0, n+1){
        posG.pb(umi());
        negG.pb(umi());
    }

    FOR(i, 0, m){
        scanf("%d %d %d\n", &x, &y, &w);
        posG[x][y].pb(w);
        negG[x][y].pb(-w);
    }

    bfs(posG, reachable);

    int negcycle = bellmanford(posG, dist, n, reachable);
    int poscycle = bellmanford(negG, distNeg, n, reachable);

    if( negcycle ) printf("-infinity ");
    else{
        auto earliest = min_element(dist.begin(), dist.end());
        printf("%d ", *earliest);
    }

    if( poscycle ) printf("infinity\n" );
    else{
        auto latest = min_element(distNeg.begin(), distNeg.end());
        printf("%d\n", -(*latest));
    }

    return 0;

}
