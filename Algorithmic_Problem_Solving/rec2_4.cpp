#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);

    int first, second;
    vector<pair<int, int> > a;
    pair<int, int> p;

    for( int i = 0; i < n; i++){
        scanf("%d %d\n", &first, &second);
        p = make_pair(first, second);

        a.push_back(p);
    }
    sort(a.begin(), a.end());
    //int prev = a[0].second;
    //bool found = false;
    int max = a[0].second;

    for( int i = 1; i < n; i++ ){
        if( a[i].second < max ){
            printf("Happy Alex\n" );
            return 0;
        }
        else{
            max = a[i].second;
        }
    }
    printf("Poor Alex\n" );
    return 0;
}
