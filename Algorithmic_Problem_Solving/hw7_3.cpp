#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int sum;

    scanf("%d\n", &n);

    if( n == 2 ){
        printf("impossible\n" );
        return 0;
    }

    if( n == 3 ){
        printf("34\n1 6 10\n" );
    }

    if( n > 3 ){
        int sum = 24 + (n-3)*(n-2)*20;
        printf("%d\n1 6 10", sum);
        for( int i = 0; i < n-3; i++ ){
            printf(" %d", 40*(i+1));
        }
        printf("\n" );
    }

    return 0;
}
