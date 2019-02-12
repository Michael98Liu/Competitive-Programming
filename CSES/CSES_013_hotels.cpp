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
typedef map<int, int> mii;
typedef set<int> si;
typedef vector<si> vsi;

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

#define MAXN 100001
#define MAXSEG (4*MAXN) // MAXSEG >= 4N
//const int INF = (int)1e9;

int arr[MAXN];

int getmin(si& left, si& right){
    int a = *(left.begin());
    int b = *(right.begin());
    return min(a, b);
}

void build(vsi&val, int k, int nl, int nr) {
    if (nl == nr) {
        val[k].pb(arr[nl]); // arr[] is the original array
        return;
    }
    int nm = (nl+nr)/2;
    build(val, 2*k+1, nl, nm);
    build(val, 2*k+2, nm+1, nr);

    int ans = getmin(val[2*k+1], val[2*k+2]);
    val[k].insert(ans);
}

// update arr[x] to v
void update(vsi& val, int k, int nl, int nr, int x, int v) {
	if(x < nl || x > nr) return; // x is outside the node's range
	if (nl == nr) { // on a leaf that manages a single element
        val[k].clear();
		val[k].pb(v);
		return;
	}
	int nm = (nl+nr)/2;
	update(val, 2*k+1, nl, nm, x, v);
	update(val, 2*k+2, nm+1, nr, x, v);

    int ans = getmin(val[2*k+1], val[2*k+2]);
    val[k].insert(ans);
}

// Get minimum in arr[l..r]
int get(vii& val, int k, int nl, int nr, int l, int r) {
    // query range is outside the node's range
	if(r < nl || l > nr) return vi();
	// node's range is entirely covered by the query range
	if(l <= nl && nr <= r) return val[k];
	int nm = (nl+nr)/2;
	vi ansLeft = get(val, 2*k+1, nl, nm, l, r);
    vi ansRight = get(val, 2*k+2, nm+1, nr, l, r);

    int ans = getmin(ansLeft, ansRight);

	return ans;
}

int main(){
    int n, m, a;
    scanf("%d %d\n", &n, &m);

    FOR(i, 1, n+1){
        cin >> a;
        arr[i] = a;
    }

    vector< map< int, int> > val;
    FOR(i, 0, MAXSEG){
        val.pb(si());
    }
    build(val, 0, 1, n);

    vi ans;
    FOR(i, 0, m){
        cin >> a;
        get()

    }

    FOR(i, 0, m){
        printf("%d\n", ans[i]);
    }
    return 0;
}
