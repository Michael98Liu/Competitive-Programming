#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n, x, y, k, ans;
    scanf("%lld\n", &n);

    for( int i = 0; i < n; i++){
        scanf("%lld %lld %lld\n", &x, &y, &k);

        if( k < max(x, y) ) printf("-1\n" );
        else{
            
        }
    }

    return 0;
}
