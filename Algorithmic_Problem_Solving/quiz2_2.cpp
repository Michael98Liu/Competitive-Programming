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

#define MAXN 200001
#define MAX_NODES 4*MAXN

int val[MAX_NODES]; // maintained value on the tree node, MAX_NODES >= 4n
// build a segment tree for range minimum query on array arr[]
// [nl, nr] is node k's managed range
int arr[MAXN];

void build(int k, int nl, int nr) {
    if (nl == nr) {
        val[k] = arr[nl]; // arr[] is the original array
        return;
    }
    int nm = (nl+nr)/2;
    build(2*k+1, nl, nm);
    build(2*k+2, nm+1, nr);
    //print(val[2*k+1], val[2*k+2]);
    val[k] = max(val[2*k+1], val[2*k+2]); // range minimum
}

// update arr[x] to v
void update(int k, int nl, int nr, int x, int v) {
	if(x < nl || x > nr) return; // x is outside the node's range
	if (nl == nr) { // on a leaf that manages a single element
		val[k] = v;
		return;
	}
	int nm = (nl+nr)/2;
	update(2*k+1, nl, nm, x, v);
	update(2*k+2, nm+1, nr, x, v);
	val[k] = max(val[2*k+1], val[2*k+2]);	// update maintained minimum
}


// Get maximum in arr[l..r]
int get(int k, int nl, int nr, int l, int r) {
    print(k, nl, nr, l, r);
    // query range is outside the node's range
	if(r < nl || l > nr) return -INF;
	// node's range is entirely covered by the query range
	if(l <= nl && nr <= r) return val[k];
	int nm = (nl+nr)/2;
	int ansLeft = get(2*k+1, nl, nm, l, r);
    int ansRight = get(2*k+2, nm+1, nr, l, r);
	return max(ansLeft, ansRight);
}

int main(){
    string s;
    int q,l;
    char r;
    char op;
    cin >> s >>q;
    int n = sz(s);

    FOR(i,0,n){
        arr[i] = (int)s[i];
    }

    build(0, 0, n-1);
    FOR(i, 0, 4*n){
        print(val[i]);
    }

    FOR(i, 0, q){
        cin >> op >> l >> r;
        l --;
        r --;
        //print(op,l,r);
        if( op == 'c'){
            arr[l] = (int)r;
            //print(v);
            update(0, 0, n-1, l, r);
            //print("here");
        }
        else if ( op == 'q' ){
            //print(l, r);
            int ans = get(0, 0, n-1,r);
            printf("%c\n", (char)ans);
        }
    }


    return 0;

}
