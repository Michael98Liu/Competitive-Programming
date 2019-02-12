#include <iostream>
using namespace std;

int main(){
    int m, a, b, c;
    scanf("%d %d %d %d\n", &m, &a, &b, &c);

    int overlap = a+b - m;
    if( overlap < 0 ) printf("possible\n" );
    else{
        if( m-overlap < c) printf("impossible\n" );
        else printf("possible\n" );
    }
}
