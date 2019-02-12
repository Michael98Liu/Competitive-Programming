#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(){
    int t;
    unsigned long a, b, c;
    scanf("%d\n", &t);

    for( int i = 0; i< t; i ++){
        scanf("%lu %lu %lu\n", &a, &b, &c);
        int count = 0;
        bitset<17> A(a);
        bitset<17> B(b);
        int aSet = A.count();
        int bSet = B.count();
        bitset<17> AS((1<<aSet)-1);
        bitset<17> BS((1<<bSet)-1);

        string as = AS.to_string();
        string bs = BS.to_string();

        unordered_set<unsigned long> bset;

        do {
            bitset<17> bPermu(bs);
            unsigned long thisb = bPermu.to_ulong();
            if( thisb < c ){
                bset.insert(thisb);
            }
            else break;

        } while( next_permutation(bs.begin(), bs.end() ));

        do{
            bitset<17> aPermu(as);
            unsigned long along = aPermu.to_ulong();
            if( along < c ){
                unsigned long toFind = c - along;
                auto it = bset.find(toFind);
                if( it!= bset.end() ) count ++;
            }
            else break;
        }while( next_permutation(as.begin(),as.end() ));


        printf("%d\n", count);
    }
}
