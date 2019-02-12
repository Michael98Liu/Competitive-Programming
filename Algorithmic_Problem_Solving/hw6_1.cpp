#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void printChosen(vector< vector< int> >& chosen){
    for( int i = 0; i < chosen.size(); i++ ){
        for( int j = 0; j < chosen[i].size(); j++ ){
            printf("%d ", chosen[i][j]);
        }
        printf("\n" );
    }
}

bool isValid(vector<string>& board, vector< vector<int> >& chosen, int n,  int x, int y){
    for( int i = x+1; i < n; i++ ){
        if( board[i][y] == '#' ) break;
        if( chosen[i][y] == 1) return false;
    }
    for( int i = x-1; i >=0; i--){
        if( board[i][y] == '#' ) break;
        if( chosen[i][y] == 1) return false;
    }
    for( int i = y+1; i<n; i++){
        if( board[x][i] == '#') break;
        if( chosen[x][i] == 1) return false;
    }
    for( int i = y-1; i >= 0; i--){
        if( board[x][i] == '#') break;
        if( chosen[x][i] == 1) return false;
    }
    return true;
}

// premption: check remaining cells and max freq

int place(vector<string>& board, vector< vector<int> >& chosen, map<int, int>& freq, int n, int count, int m){
    //printChosen(chosen);
    //printf("Count: %d m: %d\n\n", count, m);

    for( int ind = m; ind < n*n; ind++){
        int j = ind % n;
        int i = (ind-j)/n;
        //printf("I J %d %d %d %d %d\n", i, j, board[i][j] == '.', chosen[i][j] == 0, isValid(board, chosen, n, i, j));
        if( board[i][j] == '.' && chosen[i][j] == 0 && isValid(board, chosen, n, i, j) ){
            chosen[i][j] = 1;
            int retCount = place(board, chosen, freq, n, count + 1, ind+1);
            chosen[i][j] = 0;

            auto it = freq.find(retCount);
            if( it == freq.end() ) freq[retCount] = 1;
            else freq[retCount] += 1;
        }
    }

    return count;
}

int main(){
    int n;
    scanf("%d\n", &n);
    string row;
    vector<string> board;
    vector< vector<int> > chosen;
    map<int, int> freq;

    for( int i = 0; i < n; i++ ){
        vector<int> vec(n, 0);
        getline(cin, row);
        board.push_back(row);
        chosen.push_back(vec);
    }

    place( board, chosen, freq, n, 0, 0);

    /*
    for( auto it = freq.begin(); it != freq.end(); it++){
        printf("%d %d\n", it->first, it->second);
    }
    */

    printf("%d %d\n", freq.rbegin()->first, freq.rbegin()->second);
    return 0;
}
