#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int rep = 1;
    int count = 1;
    char current;
    string str;

    getline(cin, str);
    current = str[0];

    for(int i =1; i < str.size(); i++){
        if(str[i] == current) count ++;
        else{
            rep = (count > rep) ? count:rep;
            count = 1;
            current = str[i];
        }
    }
    rep = (count > rep) ? count:rep;
    printf("%d", rep);
    return 0;
}
