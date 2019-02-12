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

int gcd(int x, int y){
    if( y == 0 ) return x;
    else return gcd(y, x%y);
}

class Node{
public:
    Node* parent;
    int rank;
    int member;
    bool counted = false;

    Node(){
        rank = 0;
        member = 1;
    }
};

void initUnionFind(vector<Node*>& Nodes){
    for( auto it = Nodes.begin(); it != Nodes.end(); it++ ){
        (*it)->parent = (*it);
        (*it)->rank = 0;
    }
}

Node* findRoot(Node* x){
    if( x->parent ==  x ) return x;
    return x->parent = findRoot(x->parent);
}

void unionNodes(Node* x, Node* y){
    Node* xRoot = findRoot(x);
    Node* yRoot = findRoot(y);
    if( xRoot->rank > yRoot->rank ) swap(xRoot, yRoot);
    if( xRoot->rank == yRoot->rank ) yRoot->rank += 1;
    if( xRoot != yRoot ){
        yRoot->member = yRoot->member + xRoot->member;
    }
    xRoot->parent = yRoot;

}

int main(){
    int n,k,s;
    vi seeds;
    cin >> n >> k;
    vector<Node*> nodes;
    FOR(i, 0, n){
        Node* n = new Node();
        nodes.pb(n);
    }

    FOR(i, 0, n){
        cin >> s;
        seeds.pb(s);
    }

    initUnionFind(nodes);

    FOR(i, 0, n-1){
        FOR(j, i+1, n){
            if( gcd(seeds[i], seeds[j]) > 1 ){
                unionNodes(nodes[i], nodes[j]);
            }
        }
    }

    vi mem;

    FOR(i, 0, n){
        Node* r = findRoot(nodes[i]);
        if( !r->counted ){
            mem.pb(r->member);
            r->counted = true;
        }
    }

    sort(all(mem));

    //pv(mem);
    int count =0;
    int reached = 0;

    for(auto it = mem.rbegin(); it != mem.rend(); it ++){
        if( count < k){
            reached += *it;
            count ++;
        }
    }

    printf("%d\n", reached);



    return 0;

}
