#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_set>
#include <set>
#include <string.h>

using namespace std;

class Book{
    int ind = 0;
    int occr = 0;
};

int main(){
    int n;
    int num;
    int money;

    while( scanf("%d\n", &n) != EOF ){

        std::vector<int> v;
        std::vector<int> s;

        for( int i = 0; i< n; i++ ){
            cin >> num;
            v.push_back(num);
            s.push_back(num);
        }

        sort(s.begin(), s.end());

        scanf("%d\n", &money);

        double half = (double)money / 2;
        int i;

        for( i = 0; i< n-1; i++){
            if( s[i] <= half && s[i+1]>= half ) break;
        }

        int j = i + 1;
        while( i >= 0 && j < n ){
            if( s[i] + s[j] == money ) break;
            else if( s[i] + s[j] > money ) i --;
            else if( s[i] + s[j] < money ) j ++;
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", min(s[i], s[j]), max(s[i], s[j]));

        scanf("\n");
    }
}
