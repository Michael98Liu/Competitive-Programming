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

vector<vl> red_dp(101, vl(100001, 0));
vector<vl> black_dp(101, vl(100001, 0));
vi a;
void solve(int n, int S, vector<vl>& dp, vi& a) {
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s <= S; s++) {
      dp[i][s] = dp[i-1][s];
      if (s - a[i] >= 0) dp[i][s] += dp[i-1][s - a[i]];
    }
  }
}

int main(){

    int n,m,a;
    cin >> n >> m;
    vi red, black;
    red.pb(0);
    black.pb(0);
    FOR(i, 0, n){
        cin >> a;
        red.pb(a);
    }
    FOR(i, 0, m){
        cin >> a;
        black.pb(a);
    }

    solve(n, 100001, red_dp, red);
    solve(m, 100001, black_dp, black);
    ll total = 0;

    FOR(i, 1, 100001){
        total += red_dp[n][i] * black_dp[m][i];
    }
    //print(total);

    if( total % 2 == 0 ) printf("bob\n" );
    else printf("alice\n");


    // vector<map<int, int>> red(n, map<int, int>());
    // vector<map<int, int>> black(m, map<int, int>());
    //
    // FOR(i, 0, n){
    //     cin >> a;
    //     FOR(j, 0, i){
    //         EACH(p, red[j]){
    //             if( contains(red[i], a + p.F) ) red[i][a + p.F] += p.S;
    //             else red[i][a + p.F] = p.S;
    //         }
    //     }
    //     if( contains(red[i], a) ) red[i][a] += 1;
    //     else red[i][a] = 1;
    // }
    //
    // int counter = 0;
    // map<int, int> redsum;
    // EACH(m, red){
    //     EACH(i, m){
    //         if( contains(redsum, i.F) ) redsum[i.F] += i.S;
    //         else redsum[i.F] = i.S;
    //     }
    // }
    //
    // EACH(i, redsum){
    //     counter += i.S;
    // }
    // print(counter);

    return 0;

}
