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
using namespace std;

#define INF 1e18
#define pv(v) for(auto &x:v) cout << x << " "; cout << endl;
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
    int n,a,b;
    vector<int> strength;
    vector<int> cost;
    cin >>n;

    for(int i = 0; i< n; i++){
        cin >> a;
        strength.push_back(a);
    }

    for(int i = 0; i< n; i++){
        cin >> b;
        cost.push_back(b);
    }

    // pv( cost);
    // pv(strength);

    vector<vector<pair<int, long long> > > dp(3, vector<pair<int, long long> >(n, make_pair(0, INF)));
    for(int i = 0; i< n; i++){
        dp[0][i] = make_pair(strength[i], cost[i]);
    }

    for(int i = 1; i< 3; i++){
        for( int j = i; j< n; j++){
            for( int k = i-1; k < j; k++){
                //print(i, j, k);
                if( strength[j] > dp[i-1][k].first ){
                    if( cost[j] + dp[i-1][k].second < dp[i][j].second ){
                        dp[i][j].first = strength[j];
                        dp[i][j].second = cost[j] + dp[i-1][k].second;
                    }
                }
            }

        }
    }
    // for( auto &vi : dp){
    //     for( auto &p: vi){
    //         cout << p.first << " " << p.second << "   ";
    //     }
    //     cout << endl;
    // }

    long long min_cost = INF;
    for( int i = 0; i< n; i++){
        min_cost = min( min_cost, dp[2][i].second );
    }

    if( min_cost == INF ) printf("Oh no!\n" );
    else printf("%lld\n", min_cost);
    return 0;
}
