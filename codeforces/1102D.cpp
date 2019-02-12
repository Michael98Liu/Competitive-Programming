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

int main(){
    int n;
    string s;
    cin >> n >> s;
    int num0 = 0, num1 = 0, num2 = 0;
    int std = n/3;

    FOR(i, 0, n){
        if( s[i] == '0' ) num0 ++;
        if( s[i] == '1' ) num1 ++;
        if( s[i] == '2' ) num2 ++;
    }

    if( num0 > std && num1 <= std && num2 <= std){
        for( int i = n-1; i >= 0; i--){
            if( s[i] == '0' ){
                if( num2 < std ){
                    s[i] = '2';
                    num2 ++;
                }
                else if( num1 < std ){
                    s[i] = '1';
                    num1 ++;
                }
                else break;
            }

        }
    }
    else if( num0 <= std && num1 > std && num2 <= std){
        FOR(i, 0, n){
            if( s[i] == '1' ){
                if( num0 < std ){
                    s[i] = '0';
                    num0 ++;
                }
                else break;
            }

        }
        for( int i = n-1; i >= 0; i--){
            if( s[i] == '1' ){
                if( num2 < std ){
                    s[i] = '2';
                    num2 ++;
                }
                else break;
            }

        }
    }
    else if( num0 <= std && num1 <= std && num2 > std){
        FOR(i, 0, n){
            if( s[i] == '2'){
                if( num0 < std ){
                    s[i] = '0';
                    num0 ++;
                }
                else if( num1 < std ){
                    s[i] = '1';
                    num1 ++;
                }
                else break;
            }

        }
    }
    else if( num0 <= std && num1 > std && num2 > std){
        FOR(i, 0, n){
            if( s[i] == '1' && num0 < std && num1 > std){
                s[i] = '0';
                num0 ++;
                num1 --;
            }
            if( s[i] == '2' && num0 < std && num2 > std){
                s[i] = '0';
                num0 ++;
                num2 --;
            }
        }
    }
    else if( num0 > std && num1 <= std && num2 > std){
        int seen0 = 0;
        FOR(i, 0, n){
            if( num1 < std ){
                if( s[i] == '2' && num2 > std ){
                    s[i] = '1';
                    num1 ++;
                    num2 --;
                }
                else if( s[i] == '0' ){
                    seen0 ++;

                    if( seen0 > std ){
                        s[i] = '1';
                        num1 ++;
                    }
                }

            }
        }
    }
    else if( num0 > std && num1 > std && num2 <= std){
        for( int i = n-1; i >= 0; i--){
            if( s[i] == '0' && num2 < std && num0 > std){
                s[i] = '2';
                num2 ++;
                num0 --;
            }
            if( s[i] == '1' && num2 < std && num1 > std){
                s[i] = '2';
                num2 ++;
                num1 --;
            }
        }
    }
    cout << s << endl;

    return 0;

}
