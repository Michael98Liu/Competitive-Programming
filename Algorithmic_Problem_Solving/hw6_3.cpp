#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>
using namespace std;

int addSurrounding(string mask, int i, int j, int n, int m){
    int toggles = int(mask[i*n + j] ) - 48;
    if( i-1 >= 0 ) toggles += int(mask[(i-1)*n +j]) - 48;
    if( i + 1 < m ) toggles += int(mask[(i+1)*n +j]) - 48;
    if( j-1 >= 0 ) toggles += int(mask[i*n + j - 1]) - 48;
    if( j+1 < n ) toggles += int(mask[i*n + j + 1]) - 48;


    return toggles;
}

bool isValid(bitset<16>& mask, vector<vector<int> >& lights, int m, int n){
    int start = 16 - m*n;
    string bitmask = mask.to_string();

    //printf("%s\n", bitmask.substr(start).c_str());

    for( int i = 0; i < m; i++){
        for( int j = 0; j < n; j++){
            if( addSurrounding(bitmask.substr(start), i, j, n, m) % 2 == lights[i][j] ) continue;
            else return false;
        }
    }
    return true;
}

int main(){
    int m, n;
    scanf("%d %d\n", &m, &n);
    string row;
    vector<vector<int> > lights;
    map<int, int> trials;
    int numOn = 0;
    int minTrial = -1;

    for( int i = 0; i < m; i++ ){
        vector<int> vec(n, 0);
        getline(cin, row);
        for( int j = 0; j < n; j++ ){
            if( row[j] == '*') vec[j] = 1;
        }

        lights.push_back(vec);
    }

    // enumerate through all subset of n elements
    for (int i = 0; i < (1<<(m*n)); i++) {
        bitset<16> mask(i);
        if( isValid(mask, lights, m, n) ){
            if( minTrial == -1) minTrial = mask.count();
            else if( mask.count() < minTrial ) minTrial = mask.count();
        }
    }

    printf("%d\n", minTrial);

    return 0;
}
