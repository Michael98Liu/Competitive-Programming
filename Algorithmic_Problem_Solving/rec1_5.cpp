#include <iostream>
using namespace std;

int main(){
    int n;
    char line[100000];

    scanf("%d\n", &n);
    for( int i = 0; i < n; i++){
        scanf("%s\n", line);

        char prev = line[0];
        int ind = 1;
        int count = 1;

        while( true ){
            if( line[ind] == '\0' ) break;
            if( line[ind] == prev ) count ++;
            else{
                if( count == 1 ) printf("%c", prev);
                else printf("%d%c", count, prev);
                prev = line[ind];
                count = 1;
            }
            ind++;
        }
        if( count == 1 ) printf("%c\n", prev);
        else printf("%d%c\n", count, prev);

    }
}
