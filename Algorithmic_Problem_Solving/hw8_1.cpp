#include <iostream>
using namespace std;

void matrix_multiply(long long** a, long long** b){
    long long mul[4][4];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            mul[i][j] = 0;
            for (int k = 0; k < 4; k++)
                mul[i][j] = (mul[i][j] + a[i][k]*b[k][j]% 1000000007) % 1000000007;
        }
    }
    /* store value in m */
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            a[i][j] = mul[i][j];
}

void matrix_power(long long** m, long long n){
    if( n ==  1 ) return;
    long long** original_m =  new long long*[4];
    for (int i = 0; i < 4; ++i) {
        original_m[i] = new long long[4];
    }

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            original_m[i][j] = m[i][j];

    matrix_power(m, n/2);

    if( n%2 == 0 ) return matrix_multiply(m, m);
    else{
        matrix_multiply(original_m, m);
        return matrix_multiply(m, original_m);
    }
}

int main(){
    long long n;
    scanf("%lld\n", &n);

    long long** m = new long long*[4];
    for (int i = 0; i < 4; ++i) {
        m[i] = new long long[4];
    }

    long long temp[4][4] = {{1,1,4,2}, {1,0,0,0}, {0,1,0,0}, {0,0,1,0}};
    long long x[4] = {7,2,1,1};

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            m[i][j] = temp[i][j];

    if( n == 1 ) printf("%d\n", 1);
    else if( n == 2 ) printf("%d\n", 2);
    else if( n == 3 ) printf("%d\n", 7);
    else{
        matrix_power(m, n-3);
        long long result = 0;

        for (int i=0; i<4; i++)
            result = (result + m[0][i] * x[i]) % 1000000007;

        printf("%lld\n", result);
    }

    return 0;
}

/*
long long calculate(long long n){
    long long result = 0;

    if( n == 0 ) return 1;

    if( n-1 >= 0) result = (result + calculate(n-1) ) % 1000000007;
    if( n-2 >= 0 ) result = (result + calculate(n-2) ) % 1000000007;
    if( n-3 >= 0 ) result = (result + 4 * calculate(n-3) ) % 1000000007;
    if( n-4 >= 0 ) result = (result + 2 * calculate(n-4) ) % 1000000007;
    return result;
}
*/
