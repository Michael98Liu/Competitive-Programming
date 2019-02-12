#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string line;
    int num, sum, n;

    scanf("%d\n", &n);

    int count = 0;

    while(count < n){
        getline(cin, line);

        sum = 0;
        istringstream ss(line);

        ss >> num;

        while(ss >> num){
            sum += num;
        }
        printf("%d\n", sum);

        count ++;
    }
}
