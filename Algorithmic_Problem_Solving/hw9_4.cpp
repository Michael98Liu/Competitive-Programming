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

/* the implementation of FenwickTree is with the help from book
    "Competitive Programming 3: the new lower bound of programming contests",
    by the Halim brothers. */
class FenwickTree{
public:
    vi ft;

    FenwickTree(long long n){
        ft.assign(n+1, 0);
    }

    int rsq(int b){
        int sum = 0;
        for(; b; b -= (b & (-b)) ){
            sum += ft[b];
        }
        return sum;
    }

    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0: rsq(a-1));
    }

    void adjust(int k, int v){
        for(;k < (int)ft.size(); k += (k & (-k)) ){
            ft[k] += v;
        }
    }
};

int main(){
    int n, x, y;
    scanf("%d\n", &n);
    vector<pair<int, int> > points;
    vector<pair<int, int> > reverse;

    FOR(i, 0, n){
        scanf("%d %d\n", &x, &y);
        points.pb(make_pair(x, y));
        reverse.pb(make_pair(y, x));
    }
    vector<pair<int, int> > original(points);
    sort( all(points) );
    sort( all( reverse));

    // map y to ft index
    map<int, int> m;
    int count = 1;
    int prev = -INF;
    FORIT(it, reverse){
        if( it->F != prev ){
            m[it->F] = count;
            count ++;
            prev = it->F;
        }
    }

    map<int, vi > columns;

    FORIT(it, points){
        auto mit = columns.find(it->F);
        if( mit == columns.end() ) columns[it->F] = vi();
        columns[it->F].push_back(it->S);
    }

    FenwickTree ft(200002);

    map<int, map<int, int> > dominate; // map x, to y, to count

    FORIT(it, columns){
        //printf("%d\n", it->F);
        FORIT(vit, it->S){
            dominate[it->F][*vit] = ft.rsq(m[*vit]);
            ft.adjust(m[*vit], 1);
        }
    }

    FORIT(it, original){
        printf("%d\n", dominate[it->F][it->S]);
    }

    return 0;
}
