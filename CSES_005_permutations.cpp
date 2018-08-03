#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v;

    if( n==4){printf("2 4 1 3\n" ); return 0;}

    int* arr = new int[n];
    for(int i = 1; i <=n; i++){
        arr[i-1] = i;
    }

    int first_len;
    int second_len;

    int* first;
    int* second;

    if( n%2 == 0){
        first_len = n/2;
        second_len = n - first_len;

        first = new int[first_len];
        second = new int[second_len];

        for( int i =1; i <= first_len; i++){
            first[i-1] = i;
        }

        for( int i=first_len+1; i <= n; i++){
            second[i - (first_len+1)] = i;
        }
    }
    else{
        first_len = (n -1)/2;
        second_len = n - first_len;

        first = new int[first_len];
        second = new int[second_len];

        for( int i =1; i <= first_len+1; i++){
            first[i-1] = i;
        }

        for( int i=first_len+2; i <= n; i++){
            second[i - (first_len+2)] = i;
        }
    }

    int i;
    for( i=0; i<= first_len && i <= second_len ; i++){
        v.push_back(first[i]);
        v.push_back(second[i]);
    }

    if( i < first_len) v.push_back(first[-1]);
    if( i< second_len) v.push_back(second[-1]);

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
