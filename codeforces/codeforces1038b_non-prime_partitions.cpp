#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    if( n < 3 ){
        printf("No\n");
        return 0;
    }

    printf("Yes\n");
    printf("%d %d\n", 1, n);
    printf("%d ", n-1);

    for( int j = 1; j < n; j++){
        if( j != n) printf("%d ", j);
    }
    printf("\n" );
    return 0;
}
