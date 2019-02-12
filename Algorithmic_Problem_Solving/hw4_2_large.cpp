#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

void add_to(map<int, int> &occ, set<int>& tree, int num){
    map<int, int>::iterator it = occ.find(num);
    if( it == occ.end() ) occ[num] = 1;
    else occ[num] += 1;
    tree.insert(num);
}

int main(){
    int n, s, num, subarray = 0;
    scanf("%d %d\n", &n, &s);
    std::vector<int> v;
    for( int i = 0; i < n; i++ ){
        cin >> num;
        v.push_back(num);
    }

    set<int> tree;
    map<int, int> occ;//map that contains the number of occurance of each number
    map<int, int>::iterator it;

    int left = 0;
    int right = 1;
    int mi = 0, ma = 0;

    while(right < n-1 && abs(v[left] - v[right]) > s){
        left ++;
        right ++;
        //printf("%d %d\n", left, right);
    }

    num = v[left];
    occ[num] = 1;
    tree.insert(num);

    num = v[right];
    it = occ.find(num);
    if( it == occ.end() ) occ[num] = 1;
    else occ[num] += 1;
    tree.insert(num);

    mi = *tree.begin();
    ma = *tree.rbegin();

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
                if( occ[num] == 0 ) tree.erase(num);
                left ++;
                mi = *tree.begin();
                ma = *tree.rbegin();
            }
            right ++;
            add_to(occ, tree, v[right]);

            mi = *tree.begin();
            ma = *tree.rbegin();
            // make sure in right range
            while( ma - mi > s && right < n-1 && left < n-1){
                num = v[left];
                occ[num] -= 1;
                if( occ[num] == 0 ) tree.erase(num);
                left ++;
                right ++;
                add_to(occ, tree, v[right]);
                mi = *tree.begin();
                ma = *tree.rbegin();
            }
        }
        else{
            right ++;
            add_to(occ, tree, v[right]);

            mi = *tree.begin();
            ma = *tree.rbegin();
        }
    }

    mi = *tree.begin();
    ma = *tree.rbegin();
    //printf("Sub %d\n", subarray);

    while( left <= n -2 ){
        if( abs(mi - ma) <= s ){
            subarray += (right - left);
            //printf("%d %d %d %d\n", v[left], v[right], left, right);
        }
        num = v[left];
        occ[num] -= 1;
        if( occ[num] == 0 ) tree.erase(num);
        left ++;

        if( tree.size() != 0 ){
            mi = *tree.begin();
            ma = *tree.rbegin();
        }
        else break;
    }

    printf("%d\n", subarray);
    return 0;
}
