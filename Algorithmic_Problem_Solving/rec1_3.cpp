#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string line;
    int num, sum, N;

    while(scanf("%d", &N) != EOF){
        sum = 0;

        for( int i = 0; i < N; i++){
            scanf("%d", &num);
            sum += num;
        }

        printf("%d\n", sum);
    }

}
