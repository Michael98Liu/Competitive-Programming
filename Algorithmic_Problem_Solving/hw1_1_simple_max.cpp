#include <iostream>
using namespace std;

int main(){
    int n;
    int max = -10000;
    int input = -10000;
    scanf("%d", &n);

    for( int i = 0; i < n; i++){
        scanf("%d", &input);
        if( input > max ) max = input;
    }
    printf("%d", max);

    return 0;
}
