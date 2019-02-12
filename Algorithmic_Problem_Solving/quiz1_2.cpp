#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    string row;
    vector<string> wheels;

    for( int i =0; i < n; i++ ){
        getline(cin, row);
        wheels.push_back(row);
    }

    bool lexi = false;
    char temp;
    for( int i = 0; i <= n; i++ ){

        if( i != 0 ){
            temp = wheels[0][0];
            for( int l = 0; l < n-1; l++ ){
                wheels[l][0] = wheels[l+1][0];
            }
            wheels[n-1][0] = temp;
        }

        for( int j = 0; j <= n; j++ ){

            if( j != 0 ){
                temp = wheels[0][1];
                for( int l = 0; l < n-1; l++ ){
                    wheels[l][1] = wheels[l+1][1];
                }
                wheels[n-1][1] = temp;
            }

            for( int k = 0; k <= n; k++ ){
                lexi = true;

                if( k != 0 ){
                    temp = wheels[0][2];
                    for( int l = 0; l < n-1; l++ ){
                        wheels[l][2] = wheels[l+1][2];
                    }
                    wheels[n-1][2] = temp;
                }
                /*
                for( auto it = wheels.begin(); it != wheels.end(); it++ ){
                    printf("%s\n", (*it).c_str());
                }
                printf("\n" );
                */
                //if( i == 1 && j == 1 && k == 0 ) return 0;

                for( int m = 0; m < n-1; m++ ){
                    if( wheels[m][0] < wheels[m+1][0] ) continue;
                    else if( wheels[m][0] == wheels[m+1][0] ){
                        if( wheels[m][1] < wheels[m+1][1] ) continue;
                        else if( wheels[m][1] == wheels[m+1][1] ){
                            if( wheels[m][2] <= wheels[m+1][2] ){
                                continue;
                            }
                            else lexi = false;
                        }
                        else lexi = false;
                    }
                    else lexi = false;
                }

                if( lexi == true ){
                    printf("%d %d %d\n", (i%n), (j%n), (k%n));
                    return 0;
                }
            }
        }
    }

    printf("impossible\n" );


    return 0;
}
