#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m, b;
    scanf("%d %d %d\n", &n, &m, &b );
    vector< string> v;
    string s;

    for( int i = 0; i < n; i++ ){
        getline(cin, s);
        v.push_back(s);
    }

    vector<bitset<8> > columnVec;
    for( int i=0; i< m; i++){
        bitset<8> column;
        for( int j = 0; j<n; j++){
            if( v[j][i] == '*' ){
                column.set(j);
            }
        }
        columnVec.push_back(column);
        column.reset();
    }

    int press = 0;
    int minPress = 2147483647;
    int lightsOn=0;

    // toggle is to apply xor
    for (int colMask = 0; colMask < (1<<n); colMask++){
        bitset<8> col(colMask);
        for( int i = 0; i < m; i++){
            columnVec[i] = columnVec[i] ^ col;
        }

        for( int rowMask = 0; rowMask < (1<<m); rowMask ++){
            bitset<50> row(rowMask);
            for( int i = 0; i < m; i++ ){
                if( row.test(i) ){
                    for( int j = 0; j < n; j++){
                        columnVec[i][j].flip();
                    }
                }
            }

            for( int i = 0; i < m; i++){
                lightsOn += columnVec[i].count();
            } // count

            press = (col.count() + row.count());
            if( lightsOn <= b ){
                if( press < minPress ) minPress = press;
            }
            //printf("%d %d\n", lightsOn, press);
            lightsOn = 0;

            for( int i = 0; i < m; i++ ){
                if( row.test(i) ){
                    for( int j = 0; j < n; j++){
                        columnVec[i][j].flip();
                    }
                }
            } // reset

            /*
            for( int i = 0; i < m; i++ ){
                printf("%s\n", columnVec[i].to_string().c_str());
            }
            printf("\n" );
            */
        }

        for( int i = 0; i < m; i++){
            columnVec[i] = columnVec[i] ^ col;
        } // reset
    }
    if( minPress == 2147483647 ) printf("-1\n" );
    else printf("%d\n", minPress);
    return 0;
}
