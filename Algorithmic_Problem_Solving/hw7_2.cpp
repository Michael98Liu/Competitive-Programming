#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    int x, y, tripCount = 0;
    vector< pair<int, int> > grid;

    for( int i = 0; i < n; i++ ){
        scanf("%d %d\n", &x, &y);
        grid.push_back(make_pair(x,y));
    }

    sort(grid.begin(), grid.end());

    auto it = grid.begin();
    int currX, currY;
    while( grid.size() != 0){
        currX = 0;
        currY = 0;
        it = grid.begin();
        while( it != grid.end() ){
            //printf("%d %d %d %d\n", currX, currY,it->first, it->second);
            if( it->first >= currX && it->second >= currY ){
                //printf("%d %d\n", currX, currY);
                currX = it->first;
                currY = it->second;
                it = grid.erase(it);
            }
            else it ++;
        }

        tripCount ++;
    }
    printf("%d\n", tripCount);

}
