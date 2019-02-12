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

struct Pair { // custom pair (vertex, distance) that compares based on distance
    vi liquid;
    int d;
    Pair(vi _x, int _d): liquid(_x.begin(), _x.end() ), d(_d) {}
    bool operator < (const Pair &ano) const { return d > ano.d; }
};

void dijkstra(vi s, int* tubes, map<vi, int>& dist) {
    priority_queue<Pair> pq;
    dist[s] = 0;
    pq.push(Pair(s, 0));

    while (!pq.empty()) {
        Pair cur = pq.top();
        pq.pop();

        auto it = dist.find(cur.liquid);
        if( it == dist.end() ) dist[cur.liquid] = INF;

        if (cur.d > dist[cur.liquid]) continue; // ignore out-of-date pair
        // iterate through all possible way to pour
        //pv(cur.liquid);
        FOR(i, 0, 5){
            if( cur.liquid[i] != 0 ){ // pour from i to j
                FOR(j, 0, 5){
                    int toPour = min(tubes[j] - cur.liquid[j], cur.liquid[i]);
                    vi newstate(cur.liquid);
                    newstate[i] -= toPour;
                    newstate[j] += toPour;

                    auto it = dist.find(newstate);
                    if( it == dist.end() ) dist[newstate] = INF;

                    if (dist[cur.liquid] + toPour < dist[newstate]) {
                        dist[newstate] = dist[cur.liquid] + toPour;
                        pq.push(Pair(newstate, dist[newstate]));
                    }
                }
            }
        }
    }
  // dist[x] now stores the weighted SP for every x
}

int main(){

    int tubes[5];
    int a,v;
    FOR(i, 0, 5){
        cin >> a;
        tubes[i] = a;
    }
    cin >> v;

    map<vi, int> dist; // map vi to distance

    dijkstra( vi({tubes[0], 0, 0, 0, 0}), tubes, dist );
    int min_cost = INF;

    FORIT(it, dist){
        if(it->F[0] == v){
            min_cost = min(min_cost, it->S);
        }
    }
    if( min_cost == INF ) printf("-1\n" );
    else printf("%d\n", min_cost);

    return 0;

}
