#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int t;
    int n;
    int num;
    scanf("%d\n", &t);

    for( int i =0; i< t; i++ ){
        vector<int> canvas;
        scanf("%d\n", &n);

        for( int j= 0; j < n; j++ ){
            scanf("%d\n", &num);
            canvas.push_back(num);
        }

        int layer = (int)log2(n) -1;

        int paint =


        printf("%d\n", paint);

    }
}
