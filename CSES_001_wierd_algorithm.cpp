#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    vector<long long> v;
    v.push_back(n);

    while( n != 1){
        if( n % 2 == 0) n /= 2;
        else n = n*3 + 1;
        v.push_back(n);
    }

    for( int i=0; i< v.size(); i++){
        printf("%lld ", v[i]);
    }

    return 0;
}
