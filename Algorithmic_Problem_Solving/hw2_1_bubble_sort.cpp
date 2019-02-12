#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, num, temp;
    long long ans = 0;
    vector<int> l;
    scanf("%d\n", &n);

    for( int i = 0; i < n; i++ ){
        scanf("%d", &num);
        l.push_back(num);
    }

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if( l[j] > l[j+1] ){
                temp = l[j];
                l[j] = l[j+1];
                l[j+1] = temp;
                ans += (long long) l[j] * l[j+1];
            }
        }
    }

    printf("%lld\n", ans);
/*
    for( int i = 0; i < n; i++ ){
        printf("%d ", l[i]);
    }

*/
    return 0;
}
