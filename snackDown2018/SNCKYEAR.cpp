#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    int year = 0;

    for( int i = 0; i < n; i++){
        scanf("%d\n", &year);
        if( year == 2010 || year == 2015 || year == 2016 || year ==  2017 || year == 2019){
            printf("HOSTED\n" );
        }
        else printf("NOT HOSTED\n" );
    }

    return 0;
}
