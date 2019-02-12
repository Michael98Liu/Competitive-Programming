#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, num;
    scanf("%d %d",&n, &k );
    std::vector<int> v;
    priority_queue<int> min_heap;
    int s, m;

    for( int i = 0; i < n; i++ ){
        scanf("%d", &num);
        if( i < k ){
            min_heap.push(-num);
            s += num;
        }
        else{
            m = -min_heap.top();
            if( num > m ){
                s -= m;
                s += num;
                min_heap.pop();
                min_heap.push(-num);
            }
        }
        printf("%d\n", s);
    }

    return 0;
}
