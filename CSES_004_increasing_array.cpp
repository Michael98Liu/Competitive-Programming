#include <stdio.h>

int main(){
    long long n, num, cur, count = 0;
    scanf("%lld", &n);

    for( int i = 0; i < n; i++){
        scanf("%lld", &num);

        if(i > 0){
            if( num < cur) count += (cur-num);
            else cur = num;
        }
        else cur = num;
    }
    printf("%lld", count);
    return 0;
}
