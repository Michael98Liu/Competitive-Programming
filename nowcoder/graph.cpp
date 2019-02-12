#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int most;
    if( m != 0 ) most = m+1;
    else most = 0;

    int least = 0;
    while( (long long)least*(least -1)/2 < m ){
        least ++;
    }
    printf("%d %d\n", max(n-most, 0), max(n-least, 0));

}
