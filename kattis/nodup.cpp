#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    string s;
    set<string> dict;

    while ( cin >> s ) {
        auto it = dict.find(s);
        if( it == dict.end() ) dict.insert(s);
        else{
            printf("no\n" );
            return 0;
        }
    }
    printf("yes\n" );
    return 0;
}
