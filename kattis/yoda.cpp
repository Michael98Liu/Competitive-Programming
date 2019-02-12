#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b;
    scanf("%d %d\n", &a, &b);
    vector<int> n;
    vector<int> m;
    int mod = 10;

    long long re;

    while( a != 0 ){
        re = a % mod;
        n.push_back((int)re*10/mod);
        a -= re;
        mod *= 10;
    }

    mod = 10;
    while( b != 0 ){
        re = b % mod;
        m.push_back((int)re*10/mod);
        b -= re;
        mod *= 10;
    }

    auto nit = n.begin();
    auto mit = m.begin();
    while(nit != n.end() && mit != m.end() ){
        if( *nit < *mit ){
            n.erase(nit);
            mit ++;
        }
        else if( *mit < *nit ){
            m.erase(mit);
            nit ++;
        }
        else{
            mit ++;
            nit ++;
        }
    }

    int are = 0;
    int bre = 0;
    mod = 1;


    for(nit = n.begin(); nit != n.end(); nit++ ){
        are += mod * (*nit);
        mod *= 10;
    }
    if( n.size() == 0) printf("YODA\n" );
    else printf("%d\n", are);

    mod = 1;
    for(mit = m.begin(); mit != m.end(); mit++ ){
        bre += mod * (*mit);
        mod *= 10;
    }
    if( m.size() == 0 ) printf("YODA\n" );
    else printf("%d\n", bre);



}
