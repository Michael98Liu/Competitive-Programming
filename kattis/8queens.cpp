#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    vector<string> board;
    for( int i = 0; i< 8; i++ ){
        cin >> s;
        board.push_back(s);
    }

    return 0;
}
