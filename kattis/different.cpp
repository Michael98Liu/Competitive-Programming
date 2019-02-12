#include <iostream>
using namespace std;

int main(){
    long long x, y;
    while( scanf("%lld %lld\n", &x, &y) != EOF ){
        printf("%lld\n", abs(x-y));
    }
}
