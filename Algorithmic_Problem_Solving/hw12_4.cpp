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
#define INF 1000000007

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

int main(){

    int n, a;
    vi array;
    cin >> n;
    FOR(i, 0, n){
        cin >> a;
        array.pb(a);
    }

    vi ans(n, 0);
    vi dp(n, 1);
    int max_dp = 1;
    int max_ind = 0;

    FOR(i, 0, n){
        FOR(j, 0, i){
            if( array[j] < array[i] ){
                dp[i] = max(dp[i], dp[j] + 1);
                if( dp[i] > max_dp ){
                    max_dp = dp[i];
                    max_ind = i;
                }
            }
        }
    }
    //pv(dp);
    vi result;

    int ind = max_ind + 1;
    max_dp = dp[max_ind]+ 1;
    int count;
    int next_max_ind;
    while( max_ind != 0 ){
        next_max_ind = 0;
        count = 0;

        while(ind >= 0){
            if( dp[ind] == max_dp-1 ){
                count ++;
                if( next_max_ind == 0) next_max_ind = ind;
            }
            ind --;
        }
        if( count == 1 ) result.pb(array[next_max_ind]);

        max_ind = next_max_ind;
        max_dp = dp[max_ind];
        ind = max_ind;
    }

    sort(all(result));

    if( sz(result) != 0 ){
        FOR(i, 0, sz(result) ){
            if( i == 0 ) printf("%d", result[i]);
            else printf(" %d", result[i]);
        }
        printf("\n" );
    }
    else printf("-1\n" );




    return 0;

}
