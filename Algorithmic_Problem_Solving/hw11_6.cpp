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

typedef unordered_set<int> usi;
typedef unordered_map<int, int> umi;
typedef unordered_map<int, usi> graph;

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

#define MAXN 100001

int label = 0;
int vnum[MAXN]; // the label of each vertex
int vlow[MAXN]; // the lowest label a vertex can reach backwards
bool pending[MAXN];
vector<int> order;
graph g;
int repla[MAXN];

void dfs(int x){
    vlow[x] = vnum[x] = ++label;
    pending[x] = true;
    order.push_back(x);
    EACH (y, g[x]) {
        if (!vnum[y]) dfs(y);
        if (pending[y]) vlow[x] = min(vlow[x], vlow[y]);
    }
    if (vlow[x] == vnum[x]) { // an SCC is found
        vector<int> scc;
        while (true) {
            int y = order.back();
            order.pop_back();
            scc.push_back(y);
            pending[y] = false;
            if (y == x) break;
        }
        sort(all(scc));
        int smallest = scc[0];
        EACH(i, scc){
            repla[i] = smallest;
        }
        // scc stores one SCC and its members
    }
}


int main(){

    int n,m,a,b;
    cin >> n >> m;

    FOR(i, 0, n){
        g[i+1] = usi();
    }

    FOR(i, 0, m){
        cin >> a >> b;
        g[a].insert(b);
    }

    memset(vnum, 0, MAXN);
    memset(vlow, 0, MAXN);
    memset(pending, false, MAXN);

    FOR(i, 0, MAXN){
        repla[i] = i;
    }

    FORIT(it, g){
        if( !vnum[it->F] ) dfs(it->F);
    }
    // shrink
    graph newg;
    FORIT(it, g){
        auto newit = newg.find(repla[it->F]);
        if( newit == newg.end() ) newg[repla[it->F]] = usi();

        FORIT(iit, it->S){
            if(repla[it->F] != repla[*iit]) newg[repla[it->F]].insert(repla[*iit]);
        }
    }

    vi indegree(MAXN, 0);
    vi outdegree(MAXN, 0);

    FORIT(it, newg){
        FORIT(iit, it->S){
            indegree[*iit] ++;
            outdegree[it->F] ++;
        }
    }

    int noin = 0, noout = 0, isolated = 0;
    EACH(ver, newg){
        if( indegree[ver.F] == 0 && outdegree[ver.F] == 0 ) isolated ++;
        else if( indegree[ver.F] == 0 ) noin++;
        else if( outdegree[ver.F] == 0 ) noout++;
    }

    int ans;

    if( noin+noout+isolated == 1 ) ans = 0;
    else ans = max(noin, noout) + isolated;
    printf("%d\n", ans);
    FOR(i, 0, ans){
        printf("1 1\n" );
    }


    return 0;

}
