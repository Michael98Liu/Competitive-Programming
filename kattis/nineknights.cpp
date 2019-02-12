#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string row;
    vector<string> board;

    for( int i = 0; i< 5; i++ ){
        cin >> row;
        board.push_back(row);
    }
    int count = 0;

    for( int i = 0; i< 5; i++ ){
        for( int j =0; j< 5; j++ ){
            if( board[i][j] == 'k' ){
                count ++;
                if( j + 1 < 5 && i + 2 < 5 ){
                    if( board[i+2][j+1] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j+ 1 < 5 && i -2 >= 0 ){
                    if( board[i-2][j+1] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j + 2 < 5 && i + 1 < 5 ){
                    if( board[i+1][j+2] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j+ 2 < 5 && i -1 >= 0){
                    if( board[i-1][j+2] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j -1 >=0 && i + 2 < 5 ){
                    if( board[i+2][j-1] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j -1 >= 0 && i - 2 >= 0 ){
                    if( board[i-2][j-1] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j -2 >=0 && i + 1 < 5 ){
                    if( board[i+1][j-2] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
                if( j -2 >= 0 && i - 1 >= 0 ){
                    if( board[i-1][j-2] == 'k' ){
                        printf("invalid\n" );
                        return 0;
                    }
                }
            }
        }
    }
    if( count == 9 ) printf("valid\n" );
    else printf("invalid\n" );
    return 0;


}
