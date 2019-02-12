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

#define MAX_N 51
#define MAX_SUM 5000
#define MID MAX_SUM
int n;
vi W(MAX_N, 0);
//vector<vector<pair<bool, bitset<51>>>> dp( MAX_N, vector<pair<bool, bitset<51>>>(MAX_SUM * 2 + 1, make_pair(false, bitset<51>(0))) );

vector<vector<vector<pair<bool, bitset<51>>>>> dp(MAX_N, vector<vector<pair<bool, bitset<51>>>>(MAX_N, vector<pair<bool, bitset<51>>>(MAX_SUM * 2 + 1, make_pair(false, bitset<51>(0)))));

int solve() {
  dp[0][0][MID].F = true;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= n; k++) {
      for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
        if (dp[i-1][k][d].F) {
          if (k+1 <= n){
              dp[i][k+1][d + W[i]].F = true;
              dp[i][k+1][d + W[i]].S = dp[i-1][k][d].S;
              dp[i][k+1][d + W[i]].S.set(i);
          }
          dp[i][k][d - W[i]].F = true;
          dp[i][k][d - W[i]].S = dp[i-1][k][d].S;
        }
      }
    }
  }
  // collect the answer by checking dp[n][*]
  int ans = INF;
  bitset<51> config;
  for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
      for( int i = (n-2)/2 + 1; i <= (n+2)/2; i++){
          if (dp[n][i][d].F){
              if( ans > abs(d - MID)){
                  ans = abs(d - MID);
                  config = dp[n][i][d].S;
              }
          }
      }
  }

    vi left;
    vi right;
    FOR(i, 1, n+1){
      if( config.test(i) ) left.pb(W[i]);
      else right.pb(W[i]);
    }

    printf("%d\n", ans);
    EACH(x, left){
      printf("%d ", x);
    }
    printf("\n" );
    EACH(x, right){
      printf("%d ", x);
    }
    printf("\n" );
  return ans;
}

// void solve() {
//     dp[0][MID].F = true;
//     for (int i = 1; i <= n; i++) {
//         for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
//             if (dp[i-1][d].F) {
//                 dp[i][d + W[i]].F = true;
//                 dp[i][d + W[i]].S = dp[i-1][d].S;
//                 dp[i][d + W[i]].S.set(i);
//                 dp[i][d - W[i]].F = true;
//                 dp[i][d - W[i]].S = dp[i-1][d].S;
//                 print(i, d+W[i]);
//                 print(i, d-W[i]);
//             }
//         }
//     }
//     // collect the answer by checking dp[n][*]
//     int ans = INF;
//     bitset<51> config;
//     for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
//         int left = dp[n][d].S.count();
//         int right = n - left;
//
//         if (dp[n][d].F && abs(left - right) <= 2){
//             if( abs(d - MID) < ans ){
//                 ans = abs(d - MID);
//                 config = dp[n][d].S;
//             }
//         }
//     }
//     vi left;
//     vi right;
//     FOR(i, 1, n+1){
//         if( config.test(i) ) left.pb(W[i]);
//         else right.pb(W[i]);
//     }
//
//     printf("%d\n", ans);
//     EACH(x, left){
//         printf("%d ", x);
//     }
//     printf("\n" );
//     EACH(x, right){
//         printf("%d ", x);
//     }
//     printf("\n" );
//
// }


int main(){
    int a;
    cin >> n;
    FOR(i, 1, n+1){
        cin >> a;
        W[i] = a;
    }
    solve();
    return 0;

}
