#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n =1, m=1, num;

    while( true ){
        scanf("%d %d\n", &n, &m);

        //printf("%d %d\n", n, m);

        if( n == 0 || m == 0 ) break;

        vector<int> dragon;
        vector<int> knight;

        for( int i = 0; i < n; i++ ){
            scanf("%d\n", &num);
            dragon.push_back(num);
        }

        for( int i = 0; i < m; i++ ){
            scanf("%d\n", &num);
            knight.push_back(num);
        }

        if( n > m ){
            printf("Loowater is doomed!\n" );
            continue;
        }

        sort(dragon.begin(), dragon.end());
        sort(knight.begin(), knight.end());

        int d = 0, k = 0;
        int pay = 0;

        while( d< n && k <m){
            while( knight[k] < dragon[d] && k < m ){
                k ++;
            }
            pay += knight[k];
            k ++;
            d ++;
        }

        if( d == n ) printf("%d\n", pay);
        else printf("Loowater is doomed!\n" );
    }

    return 0;
}
