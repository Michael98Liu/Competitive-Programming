#include <iostream>
#include <map>
using namespace std;

int main(){
    char* alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n, k;
    scanf("%d %d\n", &n, &k);

    char str[100000];
    scanf("%s\n", str);

    map<char, int>::iterator it;
    map<char, int> vocab;

    for( int i = 0; i < k; i ++){
        vocab[alpha[i]] = 0;
    }

    for( int i = 0; i < n; i ++ ){
        it = vocab.find(str[i]);
        it->second += 1;
    }

    int min = 10000000;

    for( it = vocab.begin(); it != vocab.end(); it ++ ){
        if( it->second < min ) min = it->second;
    }

    printf("%d\n", min * k);
}
