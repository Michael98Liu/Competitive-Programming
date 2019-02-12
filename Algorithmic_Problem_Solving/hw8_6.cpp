#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, num;
    scanf("%d\n", &n);

    vector<int> a;
    vector<int> b;

    for( int i = 0; i< n; i++ ){
        cin >> num;
        a.push_back(num);
    }

    for( int i = 0; i< n; i++ ){
        cin >> num;
        b.push_back(num);
    }

    map<int, int> xora;
    map<int, int> xorb;

    for( int i = 0; i <n-1; i++ ){
        for( int j = i + 1; j < n; j++ ){
            int xored = a[i] ^ a[j];
            auto it = xora.find(xored);
            if( it == xora.end() ) xora[xored] = 1;
            else xora[xored] += 1;
        }
    }

    for( int i = 0; i <n-1; i++ ){
        for( int j = i + 1; j < n; j++ ){
            int xored = b[i] ^ b[j];
            auto it = xorb.find(xored);
            if( it == xorb.end() ) xorb[xored] = 1;
            else xorb[xored] += 1;
        }
    }

    long long result = 0;

    for( auto it = xora.begin(); it != xora.end(); it ++ ){
        auto bit = xorb.find(it->first);
        if( bit != xorb.end() ) result += (long long)it->second * bit->second;
    }

    printf("%lld\n", result);
}
