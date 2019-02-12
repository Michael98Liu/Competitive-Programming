#include <iostream>
#include <bitset>
using namespace std;

int main(){
    unsigned long n = 0;
    bitset<31> mask_a(0);
    bitset<31> mask_b(0);
    //printf("%s %s\n", mask_a.to_string().c_str(), mask_b.to_string().c_str());
    scanf("%lu\n", &n);

    while( n!= 0){
        bitset<31> nbit(n);
        //printf("%s\n", nbit.to_string().c_str());
        int count = 0;
        for( int i = 0; i < 31; i++){
            if( nbit.test(i) ){
                count ++;
                if( count %2 == 0 ) mask_b.set(i);
                else mask_a.set(i);
            }
        }

        printf("%lu %lu\n", mask_a.to_ulong(), mask_b.to_ulong());
        //printf("%s %s\n", mask_a.to_string().c_str(), mask_b.to_string().c_str());
        scanf("%lu\n", &n);
        mask_a.reset();
        mask_b.reset();
    }

    return 0;
}
