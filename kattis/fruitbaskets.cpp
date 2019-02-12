/* Since it is gauranteed that baskets containing at least 4 fruits will satisfy the requirement of 200 grams,
    we can just enumerate how many baskets a fruit can be in by using (n-1) choose k, where k is between n-1 and 3.
    We should also add the weight of baskets that contain no more than 3 fruits but also weight more than 200 grams. */

#include <iostream>
#include <vector>
using namespace std;

long long nChoosek( long long n, long long k ){

    if( k > n ){
        return 0;
    }
    if( k * 2 > n ){
        k = n-k;
    }
    if( k == 0 ){
        return 1;
    }

    long long ans = n;
    for( int i = 2; i <= k; ++i ) {
        ans *= (n-i+1);
        ans /= i;
    }

    return ans;
}

int main(){
    int n;
    scanf("%d\n", &n);
    vector<int> v;
    int num;
    long long ans = 0;

    for( int i = 0; i < n; i++ ){
        scanf("%d", &num);
        v.push_back(num);
    }

    for( int i = 0; i < n; i++ ){
        if( v[i] >= 200 ) ans += v[i];
    }

    if( n == 1){
        printf("%lld\n", ans);
        return 0;
    }

    // count two combinations
    for( int i = 0; i < n; i++ ){
        for( int j = i + 1; j < n; j++ ){
            if( v[i] + v[j] >= 200 ) ans += (v[i] + v[j]);
        }
    }

    if( n == 2 ){
        printf("%lld\n", ans);
        return 0;
    }

    // three
    for( int i = 0; i < n; i++ ){
        for( int j = i + 1; j < n; j++ ){
            for( int k = j+1; k < n; k ++ ){
                if( v[i] + v[j] + v[k]>= 200 ) ans += (v[i] + v[j] + v[k]);
            }
        }
    }

    if( n == 3 ){
        printf("%lld\n", ans);
        return 0;
    }

    // n > 4
    long long comb = 0;
    for( int k = n-1; k >= 3; k-- ){
        comb += nChoosek(n-1, k);
    }

    int sum = 0;
    for( int i = 0; i < n; i++){
        sum += v[i];
    }

    ans += (long long)comb * sum;

    printf("%lld\n", ans);
}
