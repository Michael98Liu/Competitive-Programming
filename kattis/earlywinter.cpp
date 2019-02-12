#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, dm;

    scanf("%d %d\n", &n, &dm);
    int d;
    vector<int> v;

    for( int i = 0; i < n; i++){
        scanf("%d\n", &d);
        v.push_back(d);
    }

    int count = 0;
    int consec = true;
    int before = false;

    for( auto it = v.begin(); it != v.end(); it++ ){
        if( *it > dm && consec ) count ++;
        else consec = false;
        if( *it <= dm ) before = true;
    }

    if( before ) printf("It hadn't snowed this early in %d years!\n", count);
    else printf("It had never snowed this early!\n" );

}
