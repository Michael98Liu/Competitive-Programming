#include <iostream>
using namespace std;


char** rotate(char ** pic, int n, int m){
    char** new_pic = new char*[m];

    for( int i = 0; i < m; i ++ ){
        char* row = new char[n];
        new_pic[i] = row;
        for( int j = 0; j < n; j ++ ){
            row[j] = pic[j][i];
        }
    }
    return new_pic;
}


char** ho_flip(char ** pic, int n, int m){
    char** new_pic = new char*[n];

    for( int i = 0; i < n; i ++ ){
        char* row = new char[m];
        new_pic[i] = row;
        for( int j = 0; j < m; j ++ ){
            row[j] = pic[i][m - j - 1];
        }
    }
    return new_pic;
}

char** ver_flip(char ** pic, int n, int m){
    char** new_pic = new char*[n];

    for( int i = 0; i < n; i ++ ){
        char* row = new char[m];
        new_pic[i] = row;
        for( int j = 0; j < m; j ++ ){
            row[j] = pic[n - i -1][j];
        }
    }
    return new_pic;
}


int main(){
    int n1, m1;
    scanf("%d %d\n", &n1,&m1);

    char** pic1 = new char*[n1];

    for( int i = 0; i < n1; i ++ ){
        char* row = new char[m1];
        pic1[i] = row;
        scanf("%s\n", row);
    }

    int n2, m2;
    scanf("%d %d\n", &n2,&m2);

    char** pic2 = new char*[n2];

    for( int i = 0; i < n2; i ++ ){
        char* row = new char[m2];
        pic2[i] = row;
        scanf("%s\n", row);
    }

    int count, max = 0, temp;
    for( int i = 0; i < 2; i ++ ){
        pic1 = ver_flip(pic1, n1, m1);

        for( int x = 0; x < 2; x ++ ){
            pic1 = ho_flip(pic1, n1, m1);

            for( int r = 0; r < 4; r ++){
                pic1 = rotate(pic1, n1, m1);
                temp = n1;
                n1 = m1;
                m1 = temp;

                for( int j = -n1; j < n2; j++ ){
                    for( int k = -m1; k < m2; k++ ){
                        // for sub image starting at every pixel in pic2, compare to pic1
                        count = 0;
                        for( int l = 0; l < n1; l ++ ){
                            for( int m = 0; m < m1; m ++ ){
                                if( j + l >= 0 && j + l < n2 && k + m >= 0 && k + m < m2 ){
                                    if( pic1[l][m] == '#' && pic2[j+l][k+m] == '#' ){
                                        count += 1;
                                    }
                                }
                            }
                        }
                        if( max < count ) max = count;
                    }
                }
            }
        }
    }

    printf("%d\n", max);




}
