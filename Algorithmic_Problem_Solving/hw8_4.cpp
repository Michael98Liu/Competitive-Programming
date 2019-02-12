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

bool isPalin(int i){
    int reverse = 0;
    int original = i;
    int re;
    while( i != 0 ){
        re = i % 10;
        reverse = reverse * 10 + re;
        i -= re;
        i /= 10;
    }
    //print(reverse);
    return reverse == original;
}

void generatePalin(vl& palin){
    vl first = {0,1,2,3,4,5,6,7,8,9};
    vl second = {00,11, 22, 33, 44, 55, 66, 77, 88, 99};
    vector<vl> table;
    table.pb(first);

    FOR(i, 0, 11){
        vl newv;
        EACH( x, *table.rbegin() ){
            newv.pb(10*x);
        }
        table.pb(newv);
        //pv(newv);
    }

    palin.insert(palin.end(), first.begin(), first.end());
    palin.insert(palin.end(), second.begin()+1, second.end());

    long long num;
    FOR(i, 2, 12){ // 13
        vl newFirst;
        vl newSecond;

        if( i%2 == 0 ){
            FOR(j, 0, 10){

                EACH(y, first){
                    num = table[i][j] + table[0][j] + y*10;
                    if( table[i][j] != 0 ) palin.pb(num); // condition
                    newFirst.pb(num);
                }
            }

            first = newFirst;
            //pv(first);
        }else{
            FOR(j, 0, 10){

                EACH(y, second){
                    long long num = table[i][j] + table[0][j] + y*10;
                    if( table[i][j] != 0 ) palin.pb(num);
                    newSecond.pb(num);
                }
            }

            second = newSecond;
            //pv(second)
        }


    }

    vector<vl> allPalin;

}

long long binarySearch(vl& palin, ll n, ll k){
    long long l = 0;
    long long r = palin.size();

    while( r -l != 1 ){
        long long m = (l+r)/2;
        //print(l, r, m);
        if( palin[m] > n ) r = m;
        else l = m;
    }
    //print(l, l+k, palin.size());

    if( palin[l] == n ) l --;
    return palin[l+k];
}

int main(){
    int q;
    scanf("%d\n", &q);
    vl palin;

    generatePalin(palin);

    //pv(palin);

    ll n, k;
    FOR(i, 0, q){
        scanf("%lld %lld\n", &n, &k);

        long long ans = binarySearch(palin, n, k);
        printf("%lld\n", ans);
    }

    return 0;
}
