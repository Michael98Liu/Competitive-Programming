#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string line;
    int num;
    int sum;

    while(getline(cin, line)){
        sum = 0;
        istringstream ss(line);

        while(ss >> num){
            sum += num;
        }
        printf("%d\n", sum);
    }
    return 0;
}
