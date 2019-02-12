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
typedef vector<vi> vii;
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

struct Pair { // custom pair (vertex, distance) that compares based on distance
    int x, y, d;
    Pair(int _x, int _y, int _d): x(_x), d(_d), y(_y) {}
    bool operator < (const Pair &ano) const { return d > ano.d; }
};

void dijkstra(int x, int y, vii& grid, vii& dist, vector<vector<char>>& direction) {
    priority_queue<Pair> pq;
    pq.push(Pair(x, y, 0));
    vector<pair<int, int> > neighbours;
    neighbours.pb(make_pair(1,0)); // b
    neighbours.pb(make_pair(0,-1)); // l
    neighbours.pb(make_pair(0,1)); // r
    neighbours.pb(make_pair(-1,0)); // t
    char direc[4] = {'b', 'l', 'r', 't'};

    int n = grid.size();
    int m = grid[0].size();

    dist[x][y] = 0;
    while (!pq.empty()) {
        Pair cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.x][cur.y]) continue; // ignore out-of-date pair

        // iterate through neighbours
        FOR(i, 0, 4){
            int new_x = cur.x + neighbours[i].F;
            int new_y = cur.y + neighbours[i].S;
            char dire = direc[i];

            if( new_x >= 0 && new_x < n && new_y >= 0 && new_y < m ){
                if(grid[new_x][new_y] == 0) continue;
                if (dist[cur.x][cur.y] + grid[new_x][new_y] < dist[new_x][new_y]) {
                    dist[new_x][new_y] = dist[cur.x][cur.y] + grid[new_x][new_y];
                    pq.push(Pair(new_x, new_y, dist[new_x][new_y]));

                    direction[cur.x][cur.y] = dire;
                    print(new_x, new_y, dire);
                }
            }

        }

    }
    // dist[x] now stores the weighted SP for every x
}


int main(){
    int n,m,a;
    scanf("%d %d\n", &n, &m);
    vii grid;
    vii dist;
    vector<vector<char> > direction;

    FOR(i, 0, n){
        grid.pb(vi());
        dist.pb(vi(m, INF));
        direction.pb(vector<char>(m, '0'));

        FOR(j, 0, m){
            scanf("%d", &a);
            grid[i].pb(a);
        }
    }

    dijkstra(0, 0, grid, dist, direction);

    FOR(i, 0, direction.size()){
        pv(direction[i]);
    }

    int x = 0;
    int y = 0;
    vector<char> ans;

    if( dist[n-1][m-1] == INF) printf("impossible\n" );
    else{

        while( x < n-1 || y < n-1 ){
            //print(x, y);
            if( direction[x][y] == 'l' ){
                y -= 1;
                ans.pb('l');
            }
            else if( direction[x][y] == 'r' ){
                y += 1;
                ans.pb('r');
            }
            else if( direction[x][y] == 'b' ){
                x += 1;
                ans.pb('b');
            }
            else if( direction[x][y] == 't' ){
                x -= 1;
                ans.pb('t');
            }
        }

        printf("%d\n", dist[n-1][m-1]);
        for( auto it = ans.begin(); it != ans.end(); it ++){
            printf("%c", *it);
        }
        printf("\n" );
    }

    return 0;

}
