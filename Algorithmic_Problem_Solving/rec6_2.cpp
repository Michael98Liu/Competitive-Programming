#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int n, d, r;
        int num;
        scanf("%d %d %d\n", &n, &d, &r );
        vector<int> morning;
        vector<int> afternoon;

        if( n ==0 && d == 0 && r==0 ) break;

        for( int i = 0; i < n; i++ ){
            cin >> num;
            morning.push_back(num);
        }

        for( int i = 0; i < n; i++ ){
            cin >> num;
            afternoon.push_back(-num);
        }

        sort(morning.begin(), morning.end());
        sort(afternoon.begin(), afternoon.end());
        int salary = 0;

        for( int i=  0; i < n; i++){
            if( morning[i]-afternoon[i] > d ){
                salary += (morning[i]-afternoon[i] - d) * r;
            }
        }

        printf("%d\n", salary);

    }

    return 0;
}
