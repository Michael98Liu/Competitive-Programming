#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, n, k;
    scanf("%d\n", &t);
    long long sum, new_sum;
    int num;

    for( int i = 0; i < t; i++){
        sum = 0;
        new_sum = 0;

        vector<int> v;
        scanf("%d %d\n", &n, &k);

        for( int j = 0; j < n; j++ ){
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());

        for( int j = 0; j< k; j++ ){
            v[n-j-1] = 1;
        }

        for( int j = 0; j< n; j++ ){
            sum += v[j];
        }

        for( int j = 0; j< n; j++ ){
            new_sum += v[j]*v[j];
        }

        if( new_sum <= sum ) printf("YES\n" );
        else printf("NO\n" );

    }
    return 0;
}
