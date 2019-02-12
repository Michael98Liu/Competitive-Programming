#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate(vector<int> col, int r){
    vector<int> vec;
    int n = col.size();
    for( int i = 0; i < n; i ++){
        vec.push_back(col[(i + r) % n]);
    }
    /*
    for( int i = 0; i < n; i ++){
        printf("%d ", vec[i]);
    }
    printf("\n" );
    */
    return vec;
}

long long compute(vector<int> col1, vector<int> col2, vector<int> col3){
    int n = col1.size();
    long long num = 0;
    long long squared = 0;
    for( int i = 0; i < n; i++ ){
        num = 0;
        num += col1[i] * 100;
        num += col2[i] * 10;
        num += col3[i];

        //printf("%lld ", num);

        squared += num*num;
    }
    //printf("\n" );
    return squared;
}

int main(){
    int n, num;
    scanf("%d\n", &n);
    vector<int> col1, col2, col3, new_col2, new_col3;

    for( int i = 0; i < n; i ++){
        scanf("%d", &num);
        col1.push_back(num);

        scanf("%d", &num);
        col2.push_back(num);

        scanf("%d", &num);
        col3.push_back(num);
    }

    long long ans;
    long long largest = -1;
    int l2, l3;

    for( int i = 0; i < n; i ++ ){
        for( int j = 0; j < n; j++ ){
            new_col2 = rotate(col2, i);
            new_col3 = rotate(col3, j);
            ans = compute(col1, new_col2, new_col3);
            if( ans > largest ){
                largest = ans;
                l2 = i;
                l3 = j;
            }
            //printf("%lld\n0 %d %d\n\n", ans, i, j);
        }
    }

    printf("%lld\n0 %d %d\n", largest, l2, l3);



    return 0;
}
