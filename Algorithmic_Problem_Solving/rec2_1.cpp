#include <iostream>
using namespace std;

int main(){
    int a,b;
    scanf("%d %d\n", &a, &b);

    if( a%2 == 0 or b%2 == 0 ) printf("Even\n" );
    else printf("Odd\n" );
}
