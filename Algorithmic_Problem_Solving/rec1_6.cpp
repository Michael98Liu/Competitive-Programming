#include <iostream>
#include <string>
using namespace std;

int main(){
    string line;
    string left = "``";
    string right = "''";
    int ind;
    int flag = 1; // left quote

    while( getline(cin, line) ){
        ind = 0;

        while( ind < line.size() ){
            if( line[ind] == '\0' ) break;
            if( line[ind] == '"' ){
                line.erase(ind, 1);

                if( flag ){
                    line.insert(ind, left);
                    flag = 0;
                }
                else{
                    line.insert(ind, right);
                    flag = 1;
                }
            }
            ind++;
        }

        printf("%s\n", line.c_str());
    }
}
