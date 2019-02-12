#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
    priority_queue<int> min_heap;//min heap
    priority_queue<int> max_heap;//max heap
    map<int, int> occ;//map that contains the number of occurance of each number
    map<int, int>::iterator it;

    int n;
    char op;
    int num;
    int mi, ma;
    int count = 0;
    cin >> n;

    for( int i = 0; i < n; i ++){
        cin >> op;
        if( op != 's' ){
            cin >> num;
            if( op == 'a' ){
                count ++;
                it = occ.find(num);
                if( it == occ.end() ) occ[num] = 1;
                else occ[num] += 1;
                min_heap.push(-num);
                max_heap.push(num);
            }
            else{
                if( occ[num] != 0 ){
                    occ[num] -= 1;
                    count --;
                }
            }
        }
        else{
            if( count == 0){
                printf("-1\n" );
                continue;
            }
            mi = -min_heap.top();
            ma = max_heap.top();
            while( occ[mi] == 0 ){
                min_heap.pop();
                mi = -min_heap.top();
            }

            while( occ[ma] == 0 ){
                max_heap.pop();
                ma = max_heap.top();
            }
            printf("%d\n", ma - mi);
        }
    }

    return 0;
}
