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

class Dish{
public:
    int ind;
    int cost;
    int remain;

    Dish(int i, int c, int r){
        ind = i;
        cost = c;
        remain = r;
    }
};

bool operator< (const Dish& lhs, const Dish& rhs){
    if( lhs.cost < rhs.cost ) return true;
    else if( lhs.cost == rhs.cost ) return lhs.ind < rhs.ind;
    else return false;
}

int main(){
    int m, n, a, t, d;
    cin >> n >> m;

    vi remain;
    vi cost;
    vector<Dish> dish;

    FOR(i, 0, n){
        cin >> a;
        remain.pb(a);
    }
    FOR(i, 0, n){
        cin >> a;
        cost.pb(a);
    }

    FOR(i, 0, n){
        Dish dis = Dish(i, cost[i], remain[i]);
        dish.pb(dis);
    }

    sort(dish.begin(), dish.end());

    int starting = 0;

    FOR(i, 0, m){
        ll c = 0;
        cin >> t >> d;
        t--; // starts from 0

        if( remain[t] >= d ){
            remain[t] -= d;
            c += (long long) cost[t] * d;
        }
        else{
            d -= remain[t];
            c += (long long) cost[t] * remain[t];
            remain[t] = 0;

            while( d > 0){
                if( starting == n){
                    c = 0;
                    break;
                }
                int cheapest = dish[starting].ind;
                //print(cheapest);

                while( remain[cheapest] == 0 ){
                    starting ++;
                    if( starting == n) break;
                    cheapest = dish[starting].ind;
                }

                if( starting == n ){
                    c = 0;
                    break;
                }
                else if( d > remain[cheapest] ){
                    d -= remain[cheapest];
                    c += (long long)remain[cheapest] * cost[cheapest];
                    remain[cheapest] = 0;
                }
                else{
                    c += (long long)d * cost[cheapest];
                    remain[cheapest] -= d;
                    d = 0;
                }
            }
        }

        cout << c << endl;
        //pv(remain);
        //pv(cost);
    }



    return 0;

}
