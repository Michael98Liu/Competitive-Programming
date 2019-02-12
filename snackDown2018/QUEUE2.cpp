#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t, n, m, k, l, a;
    scanf("%d\n", &t);

    for( int i = 0; i < t; i++ ){
        int minwaiting = INT_MAX;
        scanf("%d %d %d %d\n", &n, &m, &k, &l);
        std::vector<int> v;

        for( int j = 0; j< n; j++){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        for( int j = 0; j< n; j++){
            a = v[j];

            if(  a < k ){
                int entered = a / l;
                if( entered >= m + j ){
                    printf("0\n" );
                    break;
                }
                int left = m - entered + j;
                printf("time: %d left: %d\n", a, left);
                int waitT = (left+1) * l + a % l;
                minwaiting = min(minwaiting, waitT);
            }
            else{
                int entered = k / l;
                int left = m - entered + j;
                int waitT = left * l + a % l;
                minwaiting = min(minwaiting, waitT);
                break;
            }
        }

        while( a < k ){
            a = a - a %l + l;
            
        }

        printf("%d\n", minwaiting);
    }
    return 0;
}
