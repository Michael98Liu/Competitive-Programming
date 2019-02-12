#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Number{
public:
    int range;
    int left;
    int right;
    int ind;

    Number(int l, int r, int i){
        range = r-l +1;
        left = l;
        right = r;
        ind = i;
    }
};

bool operator< (const Number& lhs, const Number& rhs){
    if( lhs.left < rhs.left ) return true;
    if( lhs.left == rhs.left ){
        if( lhs.range < rhs.range ) return true;
        else if( lhs.range == rhs.range ){
            if( lhs.right < rhs.right ){
                return true;
            }
            else if( lhs.right == rhs.right ){
                return lhs.ind < rhs.ind;
            }
            else return false;
        }
        else return false;
    }
    else return false;

}

int main(){
    int n, l, r;
    vector<Number> v;
    scanf("%d\n", &n);
    int* a = new int[n];
    bool* b = new bool[n+1];

    for( int i = 0; i <= n; i ++ ){
        b[i] = true; // available
    }

    for( int i = 0; i < n; i++ ){
        scanf("%d %d\n", &l, &r);
        v.push_back(Number(l, r, i));
    }

    int curr;

    while( v.size() != 0 ){

        sort(v.begin(), v.end());
        auto it = v.begin();
        printf("%d %d %d\n", it->left, it->right, it->ind);

        curr = it->left;
        while( curr <= it->right && b[curr] == false){
            curr ++;
        }
        if( curr > it->right ){
            printf("no solution\n");
            return 0;
        }
        else{
            a[it->ind] = curr;
            b[curr] = false;
            v.erase(it);
            printf("%d\n", curr);
        }

        for( it = v.begin(); it != v.end(); it++ ){
            if( it->left <= curr && it->right >= curr ) it->range --;
        }
    }

    for( int i = 0; i < n; i++ ){
        printf("%d ", a[i]);
    }

    printf("\n" );
    return 0;
}
