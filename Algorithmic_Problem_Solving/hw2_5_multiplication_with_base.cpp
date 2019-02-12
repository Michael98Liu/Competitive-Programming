#include <iostream>
#include <string.h>
using namespace std;

/*
long long pow(int base, int power){
    long long ans = 1;
    for( int i =  0; i < power; i ++ ){
        ans = (long long) (ans * base) % 1000000007;
    }
    //printf("ans %lld\n",ans );
    return ans;
}
*/

int main(){
    int base;
    scanf("%d", &base);
    char a[1000000];
    char b[1000000];
    memset(a, 0, 1000000);
    memset(b, 0, 1000000);
    scanf("%s", a);
    scanf("%s", b);

    int ind = 0, ord = 0;

    long long num1 = 0;
    long long num2 = 0;

    while( a[ind] >= 48 && a[ind] <= 122) ind++; // find the largest index
    //printf("%d\n", ind);

    for( int i = 0; i < ind; i ++ ){
        ord = (int) a[i];
        if( ord >= 97 ) ord -= 87;
        else if( ord < 97 && ord >= 65 ) ord -= 29;
        else ord -= 48;
        //printf("ord %d\n", ord);
        num1 = (long long)((long long)(num1 * base % 1000000007) + ord) % 1000000007;
    }

    ind = 0;
    while( b[ind] >= 48 && b[ind] <= 122) ind++; // find the largest index

    for( int i = 0; i < ind; i ++ ){
        ord = (int) b[i];
        if( ord >= 97 ) ord -= 87;
        else if( ord < 97 && ord >= 65 ) ord -= 29;
        else ord -= 48;
        //printf("ord %d ind %d\n", ord, ind);
        num2 = (long long)((long long)(num2 * base % 1000000007) + ord) % 1000000007;
    }

    long long ans = num1 * num2 % 1000000007;

    printf("%lld\n", ans);
    return 0;
}
