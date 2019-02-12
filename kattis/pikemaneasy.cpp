#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, t, a, b, c, t0;

    scanf("%d %d\n", &n, &t);
    scanf("%d %d %d %d\n", &a, &b, &c, &t0);

    vector<int> v;
    int m = n;
    while( m> 0 ){
        v.push_back(t0);
        t0 = ( (long long) t0 * a + b) % c + 1;
        m--;
    }

    long long penalty = 0;
    long long total_time = 0;

    sort(v.begin(), v.end());
    int i = 0;

    for( i = 0; i < n; i++ ){
        total_time += v[i];
        if( total_time > t ) break;
        penalty = (penalty + total_time) % 1000000007;
    }

    printf("%d %lld\n", i, penalty);
}
