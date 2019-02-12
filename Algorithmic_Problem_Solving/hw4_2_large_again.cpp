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

    while( right <= n-1 ){
        while( abs(mi-ma) <= s && right <= n-1 ){
            //printf("%d %d\n", mi, ma);
            subarray += (right - left);
            //printf("%d %d\n", left, right);
            right ++;
            add_to(occ, tree, v[right]);
            mi = *tree.begin();
            ma = *tree.rbegin();
        }

        while( abs(mi-ma) > s && left != right){
            num = v[left];
            occ[num] -= 1;
            if( occ[num] == 0 ) tree.erase(num);
            left ++;
            mi = *tree.begin();
            ma = *tree.rbegin();
        }

        if( left == right ){
            right ++;
            add_to(occ, tree, v[right]);
            mi = *tree.begin();
            ma = *tree.rbegin();
        }

    }

    printf("%d\n", subarray);
    return 0;
}
