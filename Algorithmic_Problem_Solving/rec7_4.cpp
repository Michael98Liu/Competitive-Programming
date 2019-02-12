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

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;

    for( int i = 0; i < n; i++ ){

        string t;
        cin >> t;

        //printf("case %s\n", t.c_str() );

        int m = 0, n = 0;
        int first = -1, last = 0;

        while( m < s.size() && n < t.size() ){
            if( s[m] == t[n] ){
                if( first == -1 )first = m;
                last = m;
                m++;
                n++;
            }
            else m ++;
        }
        if( n != t.size() ) printf("Not matched\n" );
        else printf("Matched %d %d\n", first, last);
    }
}
