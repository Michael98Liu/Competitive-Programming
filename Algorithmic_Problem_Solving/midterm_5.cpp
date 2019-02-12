#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>

using namespace std;

bool hasRook(vector<string>& board, vector<vector<bool > >& taken, int x, int y, int n){
    for( int i = 0; i < n; i++){
        if( taken[x][i] == true) return true;
    }

    for( int i = 0; i < n; i++){
        if( taken[i][y] == true) return true;
    }

    return false;
}

bool checkValid(vector<string>& board, vector<vector<bool > >& taken, int n){
    // check treasure
    for( int i = 0; i< n; i++){
        for( int j = 0; j<n; j++){
            if( board[i][j] == '*' ){
                if( hasRook(board, taken, i, j, n) ) continue;
                else return false;
            }
        }
    }

    return true;
}

bool hasTreasure(vector<string>& board, int x, int y, int n){
    for( int i = 0; i < n; i++){
        if( board[x][i] == '*') return true;
    }

    for( int i = 0; i < n; i++){
        if( board[i][y] == '*') return true;
    }

    return false;
}

int placeRook(vector<string>& board, vector<vector<bool > >& taken, int num, int n, int k, int prev){
    int count = 0;
    int curr = 0;
    //printf("num %d %d\n", num, k);

    if( num == k ){
        /*
        for( int i = 0; i< n; i++){
            for( int j = 0; j<n; j++){
                if(taken[i][j]) printf("1 ");
                else printf("0 ");
            }
            printf("\n" );
        }
        printf("\n" );*/

        if( checkValid(board, taken, n) ){



            return 1;
        }

        else return 0;
    }

    for( int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
            curr = i * n + j;

            if( curr > prev ){
                //printf("%d %d\n", curr, prev);
                if( !hasRook(board, taken, i, j, n) ){
                    //printf("no rook\n" );

                    if( board[i][j] != '*' && taken[i][j] == false ){
                        //printf("not taken\n" );
                        if( hasTreasure(board, i, j, n) ){
                            //printf("has treasure\n" );
                            taken[i][j] = true;
                            count += placeRook(board, taken, num + 1, n, k, curr);
                            taken[i][j] = false;
                        }
                    }
                }
            }

        }
    }

    return count;
}

int main(){
    int n, k;
    string row;
    vector<string> board;
    vector< vector<bool> > taken;

    scanf("%d %d\n", &n, &k);

    for( int i =0 ; i< n; i++){
        cin >> row;
        board.push_back(row);
        vector<bool> b;

        for( int j = 0 ; j < n; j++){
            b.push_back(false);
        }
        taken.push_back(b);
    }

    int count = placeRook(board, taken, 0, n, k, -1);

    printf("%d\n", count);

    return 0;
}
