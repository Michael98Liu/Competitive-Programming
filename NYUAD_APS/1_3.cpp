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


int main(){
    string a, b;
    int rem = 0, result = 0;
    int opa = 0, opb = 0;

    while(true){
        rem = 0;
        cin >> a >> b;
        if( cin.eof() ){
            break;
        }

        int i = a.size()-1;
        int j = b.size()-1;
        string ans;

        while( i > -1 || j > -1 ){
            result = 0;

            if( i>=0 ){
                if( a[i] >= 97 ) opa = a[i]-87;
                else opa = a[i] - 48;
            }
            else{
                opa = 0;
            }

            if( j >= 0 ){
                if( b[j] >= 97 ) opb = b[j]-87;
                else opb = b[j] - 48;
            }
            else opb = 0;

            result = opa + opb + rem;

            if( result >= 20 ){
                rem = 1;
                result -= 20;
            }
            else rem = 0;

            if( result >= 10 ){
                result += 87;
            }
            else result += 48;

            ans.insert(0, string(1, (char)result));

            i --;
            j --;
        }

        if( rem == 1){
            string one = "1";
            ans = one + ans;
        }

        printf("%s\n", ans.c_str());

    }




    return 0;

}
