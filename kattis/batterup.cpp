#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    int num;
    int sum = 0;
    int count = 0;

    for( int i =0; i < n; i++ ){
        scanf("%d", &num);
        if( num != -1 ){
            sum += num;
            count ++;
        }
    }

    printf("%f\n", (double)sum/count);
}
