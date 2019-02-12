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
#include <tuple>

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

int main(){
    int n,a;
    cin >> n;
    vi w;
    vi b;
    unordered_map<int, unordered_set<int>> white;
    unordered_map<int, unordered_set<int>> black;

    FOR(i, 0, n){
        cin >> a;
        white[a-1].insert(i);
        w.pb(a-1);
    }

    FOR(i, 0, n){
        cin >> a;
        black[a-1].insert(i);
        b.pb(a-1);
    }

    queue<pi> q;
    vector<vector<tuple<int, int, int>>> path; // through black or white or unreachable
    FOR(i, 0, n){
        path.pb( vector<tuple<int, int, int> >() );
        q.push(make_pair(i, i));

        FOR(j, 0, n){
            if( i == j ) path[i].pb(tuple<int, int, int>(0, i, j));
            else path[i].pb(tuple<int, int, int>(-1, -1, -1));
        }
    }

    pi cur;
    int c, d;

    /* this part of code is written by myself with the help from Fabian Gundlach's solution on
     http://acmgnyr.org/year2015/solutions/f.cpp */
    while(!q.empty()) {
        cur = q.front();
        c = cur.F;
        d = cur.S;
		q.pop();
        //print(c, d);

        FORIT(cit, white[c]){
            FORIT(dit, white[d]){
                if( get<0>(path[*cit][*dit]) == -1 ){
                    get<0>(path[*cit][*dit]) = 1;
                    get<1>(path[*cit][*dit]) = c;
                    get<2>(path[*cit][*dit]) = d;
                    q.push(make_pair(*cit, *dit));
                    //print(*cit, *dit, 'w');
                }
            }
        }

        FORIT(cit, black[c]){
            FORIT(dit, black[d]){
                if( get<0>(path[*cit][*dit]) == -1 ){
                    get<0>(path[*cit][*dit]) = 2;
                    get<1>(path[*cit][*dit]) = c;
                    get<2>(path[*cit][*dit]) = d;
                    q.push(make_pair(*cit, *dit));
                    //print(*cit, *dit, 'b');
                }
            }
        }
	}

    int x = 0;
    int y = 0;
    int temp_x;

    string ans;
    vi pos(n, 0);
    FOR(i, 0, n){
        pos[i] = i;
    }
    x = pos[0];

    FOR(i, 1, n){
        y = pos[i];
        //print(i);
        // make x and y meet each other
        while(get<0>(path[x][y]) != 0){
            //print(x, y, get<0>(path[x][y]));

            if( get<0>(path[x][y]) == 1){
                FOR(j, i+1, n){
                    pos[j] = w[pos[j]];
                }
                //print('w');
                ans += 'w';
            }
            else if( get<0>(path[x][y]) == 2){
                FOR(j, i+1, n){
                    pos[j] = b[pos[j]];
                }
                //print('b');
                ans += 'b';
            }
            else if( get<0>(path[x][y]) == -1 ){
                printf("impossible\n" );
                return 0;
            }

            temp_x = get<1>(path[x][y]);
            y = get<2>(path[x][y]);
            x = temp_x;
            //print(x, y, get<0>(path[x][y]));

        }
    }

    printf("%s\n", ans.c_str());


    return 0;

}
