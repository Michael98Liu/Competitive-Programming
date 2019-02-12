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

string bfs(bitset<101> start, vi& black, vi& white, int n){

    queue<tuple<bitset<101>, string> > q;
    unordered_set<bitset<101>> graph;
    q.push(make_tuple(start, string("") ) );
    graph.insert(start);

    while(!q.empty()){
        auto t = q.front();
        bitset<101> x = get<0>(t);
        string s = get<1>(t);
        q.pop();
        bitset<101> newx;

        // black
        FOR(i, 1, n+1){
            if( x.test(i) ) newx.set(black[i]);
        }
        if( newx.count() == 1 ) return s + 'b';

        auto it = graph.find(newx);
        if( it == graph.end() ){
            q.push(make_tuple(newx, s + 'b'));
            graph.insert(newx);
        }
        // white
        newx.reset();
        FOR(i, 1, n+1){
            if( x.test(i) ) newx.set(white[i]);
        }
        if( newx.count() == 1 ) return s+'w';

        it = graph.find(newx);
        if( it == graph.end() ){
            q.push(make_tuple(newx, s + 'w'));
            graph.insert(newx);
        }
    }

    return string("0");
}

int main(){
    int n,a;
    vi white;
    vi black;
    cin >>n;
    white.pb(0);
    black.pb(0);

    FOR(i, 0, n){
        cin >> a;
        white.pb(a);
    }

    FOR(i, 0, n){
        cin >> a;
        black.pb(a);
    }

    bitset<101> start;
    FOR(i, 1, n+1){
        start.set(i);
    }

    string ans = bfs(start, black, white, n);
    if(ans[0] =='0') printf("impossible\n" );
    else printf("%s\n", ans.c_str());

    return 0;

}
