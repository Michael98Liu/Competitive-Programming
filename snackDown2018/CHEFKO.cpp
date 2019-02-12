#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int main(){
    int t, k, n, l, r
    scanf("%d\n", &t);

    for( int i = 0; i < t; i++ ){
        scanf("%d %d\n", &n, &k);
        vector<bitset<10000> > v;
        

        for( int j = 0; j < n; j++ ){
            scanf("%d %d\n", l, r);
            v.push_back(Interval(l, r));
        }
        sort( v.begin(), v.end() );


    }

}
