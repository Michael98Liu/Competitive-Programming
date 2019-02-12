#include <iostream>
using namespace std;

int main(){
    int t;
    scanf("%d\n", &t);
    int n, m, x, y;

    for(int i = 0; i < t; i++){
        scanf("%d %d %d %d\n", &n, &m, &x, &y);
        int ans =0;
        x --;
        y --;

        int total = m*n;

        for( int j = 0; j < n; j++){
            for( int k = 0; k< m; k++){
                ans += (total - m - n + 1 - min(j, k) - min(j, m-k-1)- min(n-j-1, k) - min(n-j-1, m-k-1));
            }
        }
        ans /= 2;
        ans -= (total - m - n + 1 - min(x, y) - min(x, m-y-1)- min(n-x-1, y) - min(n-x-1, m-y-1)); // j = x, k = y
        // calculate combination
        //printf("...%d\n", x*(n-x) + y*(m-y)+min(x, y)*min(n-x-1, m-y-1) + min(x, m-y-1)*min(n-x-1, y));
        ans += x*(n-x-1) + y*(m-y-1) + min(x, y)*min(n-x-1, m-y-1) + min(x, m-y-1)*min(n-x-1, y);

        printf("%d\n", ans*2);
    }



}
