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
    int temp = 0;
    vector<int> result;
    vector<int> stack;

    while( s[current] == 'L' ){
        stack.append(current);
        current ++;
    }
    result.append(current+1);

    while( current < n ){
        if( s[current] == 'R' ){

            len_l = getNextL(current, s);
            for( int i = 1; i <= len_l; i++ ){
                stack.push_back(current + i);
            }
            current = current + len_l + 1;

            len_r = getNextR(current, s);

        }
        else if( s[current] == 'L' ){
            temp = stack.back();
            result.push_back(temp);
            stack.pop_back();
            current += 1;
        }

    }

    for( int i = 0; i < n; i ++ ){
        printf("%d\n", result[i] + 1);
    }
    return 0;
}
