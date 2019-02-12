#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_set>
#include <set>
#include <string.h>

using namespace std;

int find_smaller(vector<int>& chimps, int h, int l, int r){
    if( r -l == 1 ){
        if( chimps[r] < h ) return chimps[r];
        else return chimps[l];
    }

    int m = (l+r)/2;
    //printf("%d %d %d\n", l, r, chimps[m]);
    if( chimps[m] >= h ) return find_smaller(chimps, h, l, m);
    else return find_smaller(chimps, h, m, r);
}

int find_larger(vector<int>& chimps, int h, int l, int r){
    if( r- l ==1 ){
        if( chimps[l] > h) return chimps[l];
        else return chimps[r];
    }

    int m = (l+r)/2;
    if( chimps[m] <= h ) return find_larger(chimps, h, m, r);
    else return find_larger(chimps, h, l, m);
}


int main(){
    int n, q, num;
    scanf("%d\n", &n);
    vector<int> chimps;

    for( int i = 0; i < n; i++ ){
        cin >> num;
        chimps.push_back(num);
    }

    scanf("%d\n", &q);

    for( int i = 0; i< q; i++){
        cin >> num;

        int s = find_smaller(chimps, num, 0, n-1);
        if( s < num ) printf("%d ", s);
        else printf("X " );

        int b = find_larger(chimps, num, 0, n-1);
        if( b > num ) printf("%d\n", b);
        else printf("X\n" );
    }
}
