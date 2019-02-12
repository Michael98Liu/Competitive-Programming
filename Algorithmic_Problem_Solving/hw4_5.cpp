#include<iostream>
#include<string>
#include<vector>
#include<bitset>
using namespace std;

int main(){

    int n, m, a, b;
    scanf("%d %d\n", &n, &m);

    string r;
    vector<string> pic_string;

    for( int i = 0; i < n; i++ ){
        getline(cin, r);
        pic_string.push_back(r);
    }

    scanf("%d %d\n", &a, &b );
    bitset<40000> pattern;
    bitset<40000> wildcard;
    bitset<40000> zero;

    for( int i = 0; i < a; i++ ){
        getline(cin, r);
        for( int j = 0; j < b; j++ ){
            if( r[j] == '#' ) pattern.set(i*b+j);
            else if( r[j] == '?' ) wildcard.set(i*b+j);
            //else reverse_pattern.set(i*b + j);
        }
    }

    int count = 0;

    for( int i = 0; i <= n-a; i ++ ){
        bitset<40000> sub_pic;

        // first sub_pic
        for( int x = 0; x < a; x++){
            for( int y = 0; y < b; y++ ){
                if( pic_string[x+i][y] == '#' ){
                    //cout << "coor" << x*b+y << endl;
                    sub_pic.set(x*b+y);
                }
            }
        }

        for( int j = 0; j <= m-b; j ++){

            if( j != 0 ){
                sub_pic >>= 1;
                //printf("Not %lu\n", sub_pic.to_ulong() );

                for( int y = 0; y < a; y++ ){

                    if( pic_string[i+y][j+b-1] == '#' ) sub_pic.set((y+1)*b-1);
                    else sub_pic.reset((y+1)*b-1);
                }
            }
            //printf("%lu\n", sub_pic.to_ulong() );
            // compare
            if ( zero == ((sub_pic | wildcard)^(pattern | wildcard)) ){
                //printf("yes\n");
                count ++;
            }
        }
    }
    printf("%d\n", count);


    return 0;
}
