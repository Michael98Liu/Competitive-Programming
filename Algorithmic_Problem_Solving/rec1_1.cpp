#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string line;
    int num, sum;

    while(getline(cin, line)){
        sum = 0;
        istringstream ss(line);

        ss >> num;

        if( num == 0 ) return 0;

        while(ss >> num){
            sum += num;
        }
        printf("%d\n", sum);
    }

}
