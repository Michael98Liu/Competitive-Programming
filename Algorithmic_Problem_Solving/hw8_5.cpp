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

bool valid(int d, int k, map<int, vi>& rest, vi& house){
    //print(d);

    map<int, vector<pair<int, int> > > range;

    FORIT(rit, rest){
        int type = rit->first;
        FORIT(vit, rit->second){
            int loc = *vit;
            int left = *vit - d;
            int right = *vit + d;
            if( range[type].size() != 0 ){
                pair<int, int> last = range[type].back();
                if( last.S >= left ){
                    range[type].pop_back();
                    range[type].pb(make_pair(last.F, right));
                }
                else{
                    range[type].pb(make_pair(left, right));
                }
            }else{
                range[type].pb(make_pair(left, right));
            }
        }
    }
    vi delta(1000001, 0);

    FORIT(rit, range){

        FORIT(vit, rit->second){
            //printf("%d %d\n", vit->F, vit->S);
            delta[max(0, vit->F)] += 1;
            if( vit->S < 1000000 ) delta[vit->S+1] -= 1;
        }
    }

    vi deltaSum(1000001, 0);
    deltaSum[0] = delta[0];


    FOR(i, 1, 1000001){
        deltaSum[i] = delta[i] + deltaSum[i-1];
    }

    FOR(i, 0, house.size() ){
        int loc = house[i];

        if( deltaSum[loc] < k ) return false;
    }

    return true;

}

int binarySearch(int l, int r, int k, map<int, vi>& rest, vi& house){

    while( r - l > 1 ){
        long long m = (l+r)/2;
        //print(l, r, m);
        if( valid(m, k, rest, house) ) r = m;
        else l = m;
    }

    if( valid(l, k, rest, house) ) return l;
    else return r;
}

int main(){
    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);

    int p, q, t;
    int maxd = 0;
    map<int, vi> rest;
    vi house;

    FOR(i, 0, n){
        scanf("%d %d\n", &p, &t);
        auto it = rest.find(t);
        if( it== rest.end() ) rest[t] = vi();
        rest[t].pb(p);

        maxd = max(maxd, p);
    }

    FORIT(it, rest){
        sort( all(it->second) );
        //pv(it->second);
    }

    FOR(i, 0, m){
        cin >> q;
        house.pb(q);
        maxd = max(maxd, q);
    }

    int ans = binarySearch(0, maxd, k, rest, house);
    printf("%d\n", ans);

    return 0;
}
