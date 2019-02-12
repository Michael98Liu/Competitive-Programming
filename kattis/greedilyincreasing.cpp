#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, num;
    scanf("%d\n", &n);

    vector<int> v;
    vector<int> result;
    for( int i = 0; i < n; i++ ){
        scanf("%d", &num);
        v.push_back(num);
    }

    result.push_back(v[0]);
    for( int i =1; i< n; i++){
        if( v[i] > *result.rbegin() ) result.push_back(v[i]);
    }


    n = result.size();
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        printf("%d ", result[i]);
    }
    printf("\n" );
    return 0;
}
