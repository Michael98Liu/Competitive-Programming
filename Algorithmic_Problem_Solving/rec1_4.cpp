#include <iostream>
using namespace std;

int main(){
    long long a, b, sum;
    while(scanf("%lld %lld\n", &a, &b) != EOF) {
        sum = a + b;
        printf("%lld\n\n", sum);
    }
    return 0;
}
