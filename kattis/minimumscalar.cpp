#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    int num;

    for( int i = 0; i < n; i++){
        int m;
        vector<int> x;
        vector<int> y;
        scanf("%d\n", &m);

        for( int j = 0; j< m; j++ ){
            scanf("%d", &num);
            x.push_back(num);
        }

        for( int j = 0; j< m; j++ ){
            scanf("%d", &num);
            y.push_back(num);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        long long product = 0;

        for( int j = 0; j < m; j++ ){
            product += (long long)x[j]*y[m-j-1];
        }

        printf("Case #%d: %lld\n", i+1, product);
    }

}
