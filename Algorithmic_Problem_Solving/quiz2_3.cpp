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

#define MAXN 200001

vi vnum(MAXN, 0);
vi vlow(MAXN, 0);
vi pending(MAXN, false);
int label = 0;

vector<int> order;
graph g;

vi dfs(int x){
    vi sccnum;

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
        sccnum.pb(sz(scc));
        // scc stores one SCC and its members
    }
    return sccnum;
}

int main(){
    int n,m,a,b,k;
    cin >> n >> m >> k;

    FOR(i, 0, n){
        g[i+1] = usi();
    }

    FOR(i, 0, m){
        cin >> a >> b;
        g[a].insert(b);
    }

    vi ans;
    FORIT(it, g){
        if( !vnum[it->F] ){
            vi ret = dfs(it->F);
            ans.insert(ans.end(), ret.begin(), ret.end());
        }
    }
    //pv(ans);
    sort(all(ans));
    ll result = 0;
    int counter = 0;
    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        if(counter < k) result += *it;
        else break;
        counter ++;
    }
    //if( sz(ans) < k ) result += (k-sz(ans));
    result = min((ll)n, result);
    printf("%lld\n", result);



    return 0;

}
