#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n, k;

    scanf("%lld %lld\n", &n, &k);
    long long resi = k % n;
    long long ans = k / n;
    long long re = 0;
    if( resi != 0 ) re = ans + 1;
    else re = ans;

    printf("%lld\n", re);
}
