#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    std::vector<int> stack;
    std::vector<int> result;
    stack.push_back(1);

    int temp = 0;

    for( int i = 0; i < n-1; i ++ ){
        if( s[i] == 'R' ){
            while( stack.size() != 0 ){
                temp = stack.back();
                result.push_back(temp);
                stack.pop_back();
            }
            if( s[i+1] == 'L'){
                stack.push_back(i+2);
            }
            else{
                result.push_back(i+2);
            }
        }
        else if( s[i] == 'L' ){
            stack.push_back(i+2);
        }
    }
    while( stack.size() != 0 ){
        temp = stack.back();
        result.push_back(temp);
        stack.pop_back();
    }

    for( int i = 0; i < result.size(); i ++ ){
        printf("%d\n", result[i]);
    }

    return 0;
}
