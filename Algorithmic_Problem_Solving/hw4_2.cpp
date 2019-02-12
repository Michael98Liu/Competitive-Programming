#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int update_max(priority_queue<int>& max_heap, map<int, int> &occ){
    int ma = max_heap.top();
    while( occ[ma] == 0 ){
        max_heap.pop();
        ma = max_heap.top();
    }
    return ma;
}

int update_min(priority_queue<int>& min_heap, map<int, int> &occ){
    int mi = -min_heap.top();
    while( occ[mi] == 0 ){
        min_heap.pop();
        mi = -min_heap.top();
    }
    return mi;
}

void add_to(vector<int>& v, map<int, int> &occ, priority_queue<int>& max_heap, priority_queue<int>& min_heap, int right){
    int num = v[right];
    map<int, int>::iterator it = occ.find(num);
    if( it == occ.end() ){
        occ[num] = 1;
        min_heap.push(-num);
        max_heap.push(num);
    }else if( occ[num] == 0 ){
        occ[num] += 1;
        min_heap.push(-num);
        max_heap.push(num);
    }
    else occ[num] += 1;
}


int main(){
    int n, s, num, subarray = 0;
    scanf("%d %d\n", &n, &s);
    std::vector<int> v;
    for( int i = 0; i < n; i++ ){
        cin >> num;
        v.push_back(num);
    }

    priority_queue<int> min_heap;//min heap
    priority_queue<int> max_heap;//max heap
    map<int, int> occ;//map that contains the number of occurance of each number
    map<int, int>::iterator it;

    int left = 0;
    int right = 1;

    int mi = 0, ma = 0;

    while(abs(v[left] - v[right]) > s && right < n-1){
        left ++;
        right ++;
        //printf("%d %d\n", left, right);
    }

    num = v[left];
    occ[num] = 1;
    min_heap.push(-num);
    max_heap.push(num);

    num = v[right];
    it = occ.find(num);
    if( it == occ.end() ) occ[num] = 1;
    else occ[num] += 1;
    min_heap.push(-num);
    max_heap.push(num);

    mi = -min_heap.top();
    ma = max_heap.top();

    while( right < n-1 ){
        //printf("R: %d\n", right );
        if( abs(v[right+1] - mi) > s || abs(v[right+1] - ma) > s ){
            // right cannot move right anymore without moving left
            //printf("%d %d\n", mi, ma);
            while( (abs(v[right+1] - mi) >s || abs(v[right+1] - ma) > s) && left != right ){
                // move left until within range again
                subarray += (right - left);
                //printf("Sub %d\n", subarray);
                //printf("%d %d %d %d\n", v[left], v[right], left, right);

                num = v[left];
                occ[num] -= 1;
                left ++;
                mi = update_min(min_heap, occ);
                ma = update_max(max_heap, occ);
            }
            right ++;
            add_to(v, occ, max_heap, min_heap, right);

            mi = update_min(min_heap, occ);
            ma = update_max(max_heap, occ);
            // make sure in right range
            while( ma - mi > s && right < n-1 && left < n-1){
                num = v[left];
                occ[num] -= 1;
                left ++;
                right ++;
                add_to(v, occ, max_heap, min_heap, right);
                mi = update_min(min_heap, occ);
                ma = update_max(max_heap, occ);
            }
        }
        else{
            right ++;
            add_to(v, occ, max_heap, min_heap, right);

            mi = update_min(min_heap, occ);
            ma = update_max(max_heap, occ);
        }
    }

    mi = update_min(min_heap, occ);
    ma = update_max(max_heap, occ);
    //printf("Sub %d\n", subarray);

    while( left <= n -2 ){
        if( abs(mi - ma) <= s ){
            subarray += (right - left);
            //printf("%d %d %d %d\n", v[left], v[right], left, right);
        }
        num = v[left];
        occ[num] -= 1;
        left ++;

        mi = update_min(min_heap, occ);
        ma = update_max(max_heap, occ);
    }

    printf("%d\n", subarray);
    return 0;
}
