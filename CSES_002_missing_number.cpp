#include <stdio.h>

int main(){
    int n, num;
    scanf("%d", &n);
    int* arr = new int[n]();


    for( int i = 0; i < n-1; i++){
        scanf("%d", &num);
        arr[num-1] = 1;
    }

    for( int i = 0; i< n; i++){
        if( arr[i] == 0){
            printf("%d", i+1);
            return 0;
        }
    }
    return 0;
}
