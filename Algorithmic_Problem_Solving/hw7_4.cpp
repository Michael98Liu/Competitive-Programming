#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Number{
public:
    int num;
    std::vector<int> ind;

    Number(int n){
        num = n;
    }
};

bool operator< (const Number& lhs, const Number& rhs){
    if( lhs.ind.size() < rhs.ind.size() ) return true;
    if( lhs.ind.size() == rhs.ind.size() ){
        if( lhs.num < rhs.num ) return false;
        else return true;
    }
    else return false;
}

int main(){
    int n, l, r;
    vector<Number> v;
    scanf("%d\n", &n);
    int* a = new int[n];

    for( int i = 0; i < n; i ++ ){
        a[i] = 0;
    }

    for( int i = 1; i <= n; i ++){
        v.push_back(Number(i));
    }

    for( int i = 0; i < n; i++ ){
        scanf("%d %d\n", &l, &r);
        for( int j = l; j <= r; j++ ){
            v[j-1].ind.push_back(i);
        }
    }


    //printf("here\n" );
    int ind;
    bool found;
    auto it = v.begin();

    while(  it != v.end() ){

        sort(v.begin(), v.end());
        //printf("Num %d\n", it->num);

        if( it->ind.size() != 0 ){
            found = false;
            while( it->ind.size() != 0 ){
                ind = it->ind.back();
                //printf("%d\n", ind);
                it->ind.pop_back();
                if( a[ind] == 0 ){
                    //printf("%d\n", ind);
                    found = true;
                    a[ind] = it->num;
                    v.erase(it);
                    break;
                }
            }
            if( found ) continue;
            else{
                printf("no solution\n");
                return 0;
            }
        }
        else{
            printf("no solution\n");
            return 0;
        }

    }

    for( int i = 0; i < n; i++ ){
        printf("%d ", a[i]);
    }

    printf("\n" );
    return 0;

}
