#include <iostream>
using namespace std;

long long nChoosek( int n, int k ){

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
    long long ans = 0;

    for( int i =2; i <= n; i++ ){
        ans += nChoosek(n, i);
    }

    printf("%lld\n", ans);

}
