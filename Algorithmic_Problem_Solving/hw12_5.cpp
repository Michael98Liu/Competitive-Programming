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
#define MOD 10000
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

int main(){
    int n,m,s,a,b,c,d;

    cin >> n >> m >> s >> a >> b >> c >> d;
    vector<vi> grid(2, vi(m, 0));
    vector<vector<bool>> reachable(2, vector<bool>(m, false));
    vector<vector<pair<int, int>>> path(2, vector<pair<int, int> >(m, make_pair(0, 0)));// coins, number of ways
    path[0][0].F = s;
    path[0][0].S = 1;
    if( s != 0) reachable[0][0] = true;
    vector<pair<int, int>> direction = {{-1, 0}, {0, -1}};

    int curLayer = 0, prevLayer = 0;
    int last = s;
    int cell = 0;
    int tempi, tempx;
    FOR(i, 0, n){
        FOR(j, 0, m){
            //print(curLayer, prevLayer);
            cell = last;
            grid[curLayer][j] = cell;
            if( cell != 0 ){
                EACH(d, direction){
                    int x = i + d.F;
                    int y = j + d.S;

                    if( x >= 0 && x < n && y >= 0 && y < m ){
                        tempi = i;
                        tempx = x;
                        if( x < i ){
                            x = prevLayer;
                            i = curLayer;
                        }else{
                            x = curLayer;
                            i = curLayer;
                        }
                        if( grid[x][y] != 0 && reachable[x][y] ){
                            reachable[i][j] = true;
                            if( path[x][y].F + grid[i][j] > path[i][j].F ){
                                path[i][j].F = path[x][y].F + grid[i][j];
                                path[i][j].S = path[x][y].S;
                                //print(i, j, path[i][j].F);
                            }
                            else if( path[x][y].F + grid[i][j] == path[i][j].F ){
                                path[i][j].S = (path[i][j].S + path[x][y].S) % MOD;
                                //print(i, j, path[i][j].F);
                            }
                        }
                        i = tempi;
                        x = tempx;
                    }
                }
            }
            last = (((last*a) ^ b) + c ) % d;
        }
        //pv(grid[curLayer]);
        prevLayer = curLayer; curLayer ^= 1; // swap the layers
        path[curLayer].assign(m, make_pair(0, 0));
        reachable[curLayer].assign(m, false);
    }

    /*
    EACH(v, path){
        EACH(p, v){
            printf("%d ", p.F);
        }
        printf("\n" );
    }
    */

    printf("%d %d\n", path[prevLayer][m-1].F, path[prevLayer][m-1].S);

    return 0;

}
