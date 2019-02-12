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
typedef unordered_map<int, vi> graph;

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
int counter = 0;

void euler(int x, graph& g){

    while (g[x].size()) {
        int y = g[x].back(); // we choose the last edge for fast removal
        g[x].pop_back(); // remove this edge so that it will not be visited again
        euler(y, g);
    }
    order.push_back(x);
}

/*
void euler(int x, graph& g){
    vi stack;
    stack.pb(x);

    while(stack.size()){
        x = stack.back();

        if( g[x].size() == 0 ){
            order.pb(x);
            stack.pop_back();
        }
        else{
            while (g[x].size()) {
                int y = g[x].back(); // we choose the last edge for fast removal
                g[x].pop_back(); // remove this edge so that it will not be visited again
                stack.pb(y);
            }
        }
    }

}
*/

int main(){
    int n;
    cin >> n;
    string s;
    int first, last;
    graph g;
    unordered_map<int, unordered_map<int, vector<string>>> words;
    unordered_map<int, int> indegree, outdegree;
    unordered_set<int> vertices;

    FOR(i, 0, n){
        cin >> s;
        first = (int)s[0];
        last = (int)s[s.size()-1];
        vertices.insert(first);
        vertices.insert(last);

        words[first][last].pb(s);
        g[first].pb(last);

        auto it = outdegree.find(first);
        if( it == outdegree.end() ) outdegree[first] = 1;
        else outdegree[first]++;
        it = indegree.find(last);
        if( it == indegree.end() ) indegree[last] = 1;
        else indegree[last]++;
    }

    int start = 0;
    bool exist = false;
    int in, out;
    FORIT(it, vertices){
        if( !exist ) start = *it;
        auto iit = indegree.find(*it);
        if( iit != indegree.end() ) in = iit->S;
        else in = 0;

        iit = outdegree.find(*it);
        if( iit != outdegree.end() ) out = iit->S;
        else out = 0;

        if( out - in == 1 ){
            if( exist ){
                printf("impossible\n" );
                return 0;
            }
            exist = true;
            start = *it;
        }
        else if( out - in > 1 || out - in < -1 ){
            printf("impossible\n" );
            return 0;
        }
    }

    euler(start, g);

    /*
    EACH(c, order){
        print((char) c);
    }
    printf("\n" );
    */


    if( order.size() != n +1 ){
        printf("impossible\n" );
        return 0;
    }

    start = *order.rbegin();
    string ans;
    //print((char) start);
    //pv(order);
    for(int i = order.size() -2; i >= 0; i --){
        //print((char) order[i]);
        ans = words[start][order[i]].back();
        printf("%s\n", ans.c_str());
        words[start][order[i]].pop_back();
        start = order[i];
    }


    return 0;

}
