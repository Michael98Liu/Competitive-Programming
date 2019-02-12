#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    scanf("%d\n", &t);

    for( int i = 0; i<t; i++){
        int n;
        string field;
        scanf("%d\n", &n);
        cin >> field;
        int count = 0;
        int ind = 0;

        while( ind < n ){
            if( field[ind] == '.' ){
                ind += 3;
                count += 1;
            }
            else{
                ind ++;
            }
        }

        printf("Case %d: %d\n", i+1, count);
    }
}
