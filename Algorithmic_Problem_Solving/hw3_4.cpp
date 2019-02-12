#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int n, q, num, count = 0;
    scanf("%d %d\n", &n,&q);

    int* inverted = new int[2001];
    memset(inverted, 0, 2001);
    
    int* array = new int[n];

    for( int* p = array; p < array + n; p ++ ){
        scanf("%d", p);
        inverted[*p] += 1;
    }

    sort( array, array + n);
    int to_find;

    for( int i = 0; i<q; i ++ ){
        scanf("%d\n", &num);
        count = 0;
        for( int j = 0; j < n; j++ ){
            to_find = num - array[j];
            //printf("%d\n", inverted[to_find]);
            if( inverted[to_find] != 0) count += inverted[to_find];
            if( to_find == array[j]) count -= 1;
        }
        printf("%d\n", count/2);
    }
}
