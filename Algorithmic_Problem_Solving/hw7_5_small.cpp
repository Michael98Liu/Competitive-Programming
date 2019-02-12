#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, x, y, s;
    scanf("%d %d %d\n", &n, &x, &y);

    vector<int> a;
    vector<int> b;

    for( int i =0; i < n; i++){
        cin >> s;
        a.push_back(s);
    }

    for( int i =0; i < n; i++){
        cin >> s;
        b.push_back(s);
    }

    int maxi = 0;
    int count;

    sort(b.begin(), b.end());

    do{

        count = 0;

        for( int i =0; i < n; i++ ){
            if( a[i] + b[i] <= y && abs(a[i] - b[i]) <= x ){
                count += 1;
            }
        }
        //printf("%d\n", count);

        if( count > maxi ) maxi = count;

    }while(next_permutation(b.begin(), b.end()));

    printf("%d\n", maxi);
}
