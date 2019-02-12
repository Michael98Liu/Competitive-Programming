#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector< vector<int> > matrix;
    vector<int> first;

    int num;
    while( scanf("%d", &num) != EOF){
        first.push_back(num);
    }

    for( int i = 0; i < first.size(); i++ ){
        printf( "%d\n", first[i] );
    }
    
    return 0;
}
