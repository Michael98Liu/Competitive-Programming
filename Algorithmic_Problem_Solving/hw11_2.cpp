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

typedef unordered_set<int> usi;
typedef unordered_map<int, int> umi;
typedef unordered_map<int, usi> graph;

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

vector<int> order;

void kahn(graph& g, int n) {
    umi indegree;
    // edge goes from x to y
    int x, y, ind;
    FORIT(it, g){
        x = it->F;
        FORIT(iit, it->S){
            y = *iit;
            auto mit = indegree.find(y);
            if( mit != indegree.end() ) indegree[y]++;
            else indegree[y] = 1;
        }
    }

    priority_queue<int> q;
    FOR(i, 0, n){
        if( i < 26 ) ind = 65+i;
        else ind = 97+i-26;

        if (indegree[ind] == 0) q.push(-ind);
    }

    while (!q.empty()) {
        int x = -q.top(); q.pop();
        order.push_back(x);
        FORIT(it, g[x]){
            y = *it;
            indegree[y]--;
            if (indegree[y] == 0) q.push(-y);
        }
    }
    // order stores a topological order
}

int main(){
    int n, k;
    cin >> n >> k;
    graph g;

    FOR(i, 0, k){
        if( i < 26 ){
            g[65+i] = usi();
        }
        else if( i >= 26 ){
            g[97+i-26] = usi();
        }
    }

    string s, prev;
    cin >> prev;
    FOR(i, 0, n-1){
        cin >> s;
        FOR(j, 0, prev.size() ){
            if( j < s.size() ){
                if( prev[j] != s[j] ){
                    g[ prev[j] ].insert(s[j]);
                    //printf("%c %c\n", prev[j], s[j]);
                    break; // first letter that is different tells the order
                }
            }else{
                printf("impossible\n" );
                return 0; // if letters all the same, latter one must be longer
            }
        }
        prev = s;
    }

    kahn(g, k);
    if( order.size() != k ){
        printf("impossible\n" );
        return 0;
    }
    else{
        FORIT(it, order){
            printf("%c", (char)(*it));
        }
        printf("\n" );

        return 0;
    }



}
