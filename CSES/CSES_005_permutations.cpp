#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v;

    int i = 1;

    while(i < n){
        v.push_back(i+1);
        i += 2;
    }
    i = 0;
    while(i < n){
        v.push_back(i+1);
        i += 2;
    }

    for( int i = 1; i < n; i++){
        if( v[i] - v[i-1]  == 1 || v[i] - v[i-1] == -1){
            printf("NO SOLUTION\n" );
            return 0;
        }
    }

    for( int i = 0; i <n; i++){
        printf("%d ", v[i]);
    }
    printf("\n" );

    return 0;
}
