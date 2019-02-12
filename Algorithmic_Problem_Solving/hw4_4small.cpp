#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;


int nChoosek( int n, int k )
{
    /* code of combinatorial is from:
    https://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c */
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
    int n, m;
    scanf("%d %d\n", &n, &m);
    int full = pow(2, m) -1;

    map<int, int> map_bit;
    string s;
    int num = 0;
    for( int i = 0; i < n; i++){
        getline(cin, s);
        num = 0;
        for( int j = 0; j < m; j++ ){
            if( s[j] == 'y' ) num += 1 << (m - j -1);
        }
        auto it = map_bit.find(num);
        if( it == map_bit.end() ) map_bit[num] = 1;
        else map_bit[num] += 1;
    }

/*
    for( auto it = map_bit.begin(); it != map_bit.end(); it ++ ){
        printf("%d\n", it->first);
    }
*/
    long long count = 0;
    int two = 0;

    for( auto it1 = map_bit.begin(); it1 != map_bit.end(); it1 ++ ){
        for ( auto it2 = it1; it2 != map_bit.end(); it2 ++ ){
            for( auto it3 = it2; it3 != map_bit.end(); it3 ++ ){
                if( (it3->first | it2->first | it1->first) == full ){

                    if( it1 == it2 && it2 == it3 ){
                        count += nChoosek(it1->second, 3);
                    }
                    else if( it1 == it2){
                        count += nChoosek(it1->second, 2) * it3->second;
                    }
                    else if( it1 == it3){
                        count += nChoosek(it1->second, 2) * it2->second;
                    }
                    else if( it2 == it3){
                        count += nChoosek(it2->second, 2) * it1->second;
                    }
                    else{
                        count += it1->second * it2->second * it3->second;
                    }
                }
            }
        }
    }

    printf("%lld\n", count);


    return 0;
}
