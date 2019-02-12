#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <assert.h>
using namespace std;
#include <chrono>


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
    auto start = std::chrono::high_resolution_clock::now();

    int n, m;
    scanf("%d %d\n", &n, &m);
    int full = pow(2, m) -1;

    map<int, int> map_bit;
    map<int, int> subsets;

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

    int M; // bitmask to be enumerated
    for( auto it = map_bit.begin(); it != map_bit.end(); it ++ ){
        M = it->first;
        for (int m = M; m >= 0; m = !m ? -1 : (M & (m - 1))){
            auto subset_it = subsets.find(m);
            if( subset_it != subsets.end() ) subsets[m] += it->second;
            else subsets[m] = it->second;
        }
    }

/*
    for( auto it = map_bit.begin(); it != map_bit.end(); it ++ ){
        printf("%d\n", it->first);
    }
*/
    long long count = 0;
    int two = 0;
    int k, notM;

    for( auto it1 = map_bit.begin(); it1 != map_bit.end(); it1 ++ ){
        for ( auto it2 = map_bit.begin(); it2 != map_bit.end(); it2 ++ ){
            if( it1->second >= 2 || it1 != it2 ){

                M = (it1->first | it2->first);
                notM = M;
                // find if ~M exist in subsets
                M = (~M) & full;
                //printf("%lld\n", count);
                //printf("%d %d %d\n\n", it1->first, it2->first, M);

                auto it = subsets.find(M);
                if( it != subsets.end() ){
                    // exists, then check if *it is a subset of it1 or it2
                    if( it1 == it2 ){
                        if(it1->second >= 2 ){
                            if( (notM | it1->first) == full ){
                                // is a subset
                                if( it1->second >= 3 ) count += nChoosek(it1->second, 3);
                                if( it->second - it1->second *2 > 0 ) count += nChoosek(it1->second, 2) * (it->second - it1->second *2);
                            }
                            else{
                                // is not a subset
                                count += nChoosek(it1->second, 2) * it->second;
                            }
                        }
                    }
                    else{
                        if( (notM | it1->first) == full && (notM | it2->first) == full){
                            assert(it->second - it1->second - it2->second >= 0);
                            count += it1->second * it2->second * (it->second - it1->second - it2->second);
                            count += nChoosek(it1->second, 2) * it2->second;
                            count += nChoosek(it2->second, 2) * it1->second;

                        }
                        else if( (notM | it1->first) == full ){
                            if( it1->second >= 2 ) count += nChoosek(it1->second, 2) * it2->second;
                            if( it->second - it1->second > 0 ) count += it1->second * (it->second - it1->second) * it2->second;
                        }
                        else if( (notM | it2->first) == full ){
                            if( it2->second >= 2 ) count += nChoosek(it2->second, 2) * it1->second;
                            if( it->second - it2->second > 0 ) count += it2->second * (it->second - it2->second) * it1->second;
                        }
                        else{
                            count += it1->second * it2->second * it->second;
                        }
                    }

                }
            }
        }
    }

    printf("%lld\n", count/3);

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = stop - start;

    // To get the value of duration use the count()
    // member function on the duration object
    //std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}
