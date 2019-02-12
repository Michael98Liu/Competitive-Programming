#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m, num;
    set<int> cd;
    set<int>::iterator it;
    int count = 0;
    scanf("%d %d\n", &n, &m);

    while( n!=0 && m!= 0){
        for( int i = 0; i < n; i ++ ){
            scanf("%d\n", &num);
            cd.insert(num);
        }

        for( int i = 0; i < m; i ++ ){
            scanf("%d\n", &num);
            it = cd.find(num);
            if( it!= cd.end() ) count += 1;
        }
        printf("%d\n", count);
        scanf("%d %d\n", &n, &m);
        cd.clear();
        count = 0;
    }

    return 0;
}
