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

void dijkstraFire(int x, int y, vii& fire) {
    priority_queue<Pair> pq;
    int n = fire.size();
    int m = fire[0].size();

    FOR(i, 0, n ){
        FOR(j, 0, m ){
            if( fire[i][j] == 0 ) pq.push(Pair(i, j, 0));
        }
    }

    vector<pair<int, int> > neighbours;
    neighbours.pb(make_pair(1,0)); // t
    neighbours.pb(make_pair(0,-1)); // r
    neighbours.pb(make_pair(0,1)); // l
    neighbours.pb(make_pair(-1,0)); // b

    while (!pq.empty()) {
        Pair cur = pq.top();
        pq.pop();
        if (cur.d > fire[cur.x][cur.y]) continue; // ignore out-of-date pair

        // iterate through neighbours
        FOR(i, 0, 4){
            int new_x = cur.x + neighbours[i].F;
            int new_y = cur.y + neighbours[i].S;

            if( new_x >= 0 && new_x < n && new_y >= 0 && new_y < m ){
                if( fire[new_x][new_y] == -1) continue; // rock
                if (fire[cur.x][cur.y] + 1 < fire[new_x][new_y]) {
                    fire[new_x][new_y] = fire[cur.x][cur.y] + 1;
                    pq.push(Pair(new_x, new_y, fire[new_x][new_y]));
                }
            }
        }
    }
}

void dijkstraPath(int x, int y, vii& fire, vii& path) {
    priority_queue<Pair> pq;
    int n = path.size();
    int m = path[0].size();

    path[x][y] = 0;
    pq.push(Pair(x, y, 0));

    vector<pair<int, int> > neighbours;
    neighbours.pb(make_pair(1,0)); // t
    neighbours.pb(make_pair(0,-1)); // r
    neighbours.pb(make_pair(0,1)); // l
    neighbours.pb(make_pair(-1,0)); // b

    while (!pq.empty()) {
        Pair cur = pq.top();
        pq.pop();
        if (cur.d > path[cur.x][cur.y]) continue; // ignore out-of-date pair

        // iterate through neighbours
        FOR(i, 0, 4){
            int new_x = cur.x + neighbours[i].F;
            int new_y = cur.y + neighbours[i].S;

            if( new_x >= 0 && new_x < n && new_y >= 0 && new_y < m ){
                if( fire[new_x][new_y] == -1 ) continue; // rock
                if (path[cur.x][cur.y] + 1 < path[new_x][new_y]) {
                    path[new_x][new_y] = path[cur.x][cur.y] + 1;

                    if( path[new_x][new_y] < fire[new_x][new_y] ){
                        pq.push(Pair(new_x, new_y, path[new_x][new_y]));
                    }
                }
            }
        }
    }
}

int main(){

    int n,m;
    scanf("%d %d\n", &n, &m);
    vii fire;
    vii path;
    vector<string> board;
    string s;
    int j_x, j_y;

    FOR(i, 0, n){
        cin >> s;
        board.pb(s);
        fire.pb(vi(m, INF));
        path.pb(vi(m, INF));

        FOR(j, 0, m){
            if( s[j] == 'F' ){
                fire[i][j] = 0;
            }
            else if( s[j] == '#' ){
                fire[i][j] = -1;
            }
            else if( s[j] == 'J' ){
                j_x = i;
                j_y = j;
            }
        }
    }

    dijkstraFire(0, 0, fire);


    /*FOR(i, 0, n){
        pv(fire[i]);
    }*/

    dijkstraPath(j_x, j_y, fire, path);

    /*FOR(i, 0, n){
        pv(path[i]);
    }*/

    int min_t = INF;
    FOR(i, 0, n){
        FOR(j, 0, m){
            if( board[i][j] == 'H' ){
                if( path[i][j] < fire[i][j] ) min_t = min(min_t, path[i][j]);
            }
        }
    }

    if( min_t == INF ) printf("-1\n" );
    else printf("%d\n", min_t);






    return 0;

}
