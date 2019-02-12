#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main(){
    string s;
    int ls = 0; // lexicalgraphically smallest that is not visited
    int current = 0;
    int n;

    scanf("%d\n", &n);
    getline(cin, s);

    int num_left = 0;
    int reserve = 0;
    vector<int> result;

    for( int i = 0; i < n-1; i++ ){
        if( s[i] == 'L' ){
            num_left ++;
            if( (i < n-2 && s[i+1] == 'R') ){
                for( int j = num_left; j >= 0 ; j --){
                    result.push_back(ls + j);
                }
                current = ls;
                ls += num_left + 1;
                num_left = 0;
            }
        }
        else if( s[i] == 'R' ){
            result.push_back(ls);
            reserve = 0;
            while( s[i+reserve+1] == 'L' ){
                reserve ++;
            }

            ls ++;
            current += reserve + 1;
            result.push_back(current);
        }
    }

    printf("%d\n", result[0] + 1);
    for( int i = 1; i < n; i ++ ){
        if( result[i] != result[i-1] ) printf("%d\n", result[i] + 1);
    }
    return 0;
}
