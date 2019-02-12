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
#include <unordered_set>
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

struct Pair { // custom pair (vertex, degree) that compares based first on degree, then on index
    int x, d;
    Pair(int _x, int _d): x(_x), d(_d) {}
    bool operator < (const Pair &ano) const {
        if( d > ano.d ) return true;
        else if( d == ano.d ) return x < ano.x;
        else return false;
    }
};

/* Reference: Finding, Counting and Listing all Triangles in
Large Graphs, An Experimental Study, by Thomas Schank and Dorothea Wagner
University of Kalrsruhe, Germany. Link to paper: https://i11www.iti.kit.edu/extra/publications/sw-fclt-05_t.pdf */

int main(){

    int n,m,a,b;
    cin >> n >> m;
    unordered_map< int, unordered_set<int> > graph;

    FOR(i, 0, m){
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<Pair> vertices;
    FORIT(it, graph){
        vertices.pb(Pair(it->F, it->S.size()));
    }

    sort(all(vertices));
    unordered_map<int, unordered_set<int> > ad;
    int intersection; // size of intersection
    ll count = 0;

    FOR(i, 1, n+1){
        ad[i] = unordered_set<int>();
    }

    FORIT(it, vertices){
        Pair v = *it; // i
        //print(v.x);
        FORIT(vit, graph[v.x]){ // j
            //print("j ", *vit);
            if( v.x < *vit ){
                intersection = 0;

                //print("size", ad[v.x].size(), ad[*vit].size());
                FORIT(it1, ad[v.x]){
                    auto it2 = ad[*vit].find(*it1);
                    if( it2 != ad[*vit].end() ) intersection ++;
                }

                count += intersection;

                ad[*vit].insert(v.x);
            }
        }
    }

    printf("%lld\n", count);
    return 0;
}
