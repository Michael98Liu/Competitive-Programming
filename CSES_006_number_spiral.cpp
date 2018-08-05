/* using math.pow() on long long results in precision loss */

#include <stdio.h>
using namespace std;
#define POW(x) x*x

int main(){
    int n;
    long long x, y, m, re;

    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%lld %lld", &x, &y);
        m = x > y ? x:y;

        if( m % 2 == 1){
            if( m == x ) re = POW((m-1)) + y;
            else if( m == y ) re = POW(m) - (x-1);
        }
        else if( m %2 == 0){
            if( m ==x ) re = POW(m) - (y-1);
            else if( m == y) re = POW((m-1)) + x;
        }
        printf("%lld\n", re);
    }

    return 0;
}
