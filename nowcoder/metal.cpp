#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n,cost;
    string s;
    cin >>n;
    int a = 100000001;
    int b = 100000001;
    int c = 100000001;
    int ab = 100000001;
    int ac = 100000001;
    int bc = 100000001;
    int abc = 100000001;

    for(int i = 0; i<n; i++){
        cin >> cost >> s;
        if( s.size() == 1){
            if( s == "A" ) a = min(a, cost);
            else if( s == "B") b = min(b, cost);
            else if( s == "C" ) c = min(c, cost);
        }
        else if( s.size() == 2){
            if( s == "AB" || s == "BA" ) ab = min(ab, cost);
            else if( s == "BC" || s == "CB" ) bc = min(bc, cost);
            else if( s == "AC" || s == "CA" ) ac = min(ac, cost);
        }
        else if( s.size() == 3){
            abc = min(abc, cost);
        }
    }
    int min_cost = min(a + b + c, min(a + bc, min(b + ac, min(c + ab, min(ab + ac, min(bc + ab, min(ac + bc, abc)))))));
    if( min_cost > 100000000 ) printf("-1\n" );
    else printf("%d\n", min_cost);
}
