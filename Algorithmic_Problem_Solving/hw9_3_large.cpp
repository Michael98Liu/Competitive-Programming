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

    FenwickTree(int n){
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


int countZero(int c){

    int count = 0;
    while( (c & 1) == 0 ){
        c = c >> 1;
        count += 1;
    }

    return count;
}

int main(){
    int n, q, c;
    scanf("%d %d\n", &n, &q);
    FenwickTree ft(n);
    vi array;

    FOR(i, 1, n+1){
        scanf("%d", &c);
        int zero = countZero(c);
        ft.adjust(i, zero);
        array.pb(zero);
    }
    scanf("\n");

    //pv(ft.ft);

    char op;
    int l, r, ans;

    FOR(i, 0, q){
        scanf("%c %d %d\n", &op, &l, &r);
        if( op == 'q' ){
            ans = ft.rsq(l, r);
            printf("%d\n", ans);
        }
        if( op == 's' ){
            int rzero = countZero(r);
            int diff = rzero - array[l-1];
            ft.adjust(l, diff);
            array[l-1] = rzero;
        }

    }


    return 0;
}
