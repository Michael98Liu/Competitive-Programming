#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n, k, num;
    vector<int> v;
    vector<int> out;
    priority_queue<int> largest;
    map<int, int> freq;

    scanf("%d %d\n", &n, &k);

    for( int i = 0; i < n; i++ ){
        cin >> num;
        v.push_back(num);
    }

    for( int i = 0; i < k; i ++ ){
        largest.push(v[i]);
        auto it = freq.find(v[i]);
        if( it == freq.end() ) freq[v[i]] = 1;
        else freq[v[i]] += 1;
    }

    int max_k = 0;
    for( int i = 0; i < n; i++ ){
        freq[v[i]] -= 1;
        if( i < (n-k)){
            largest.push(v[i+k]);
            auto it = freq.find(v[i+k]);
            if( it == freq.end() ) freq[v[i+k]] = 1;
            else freq[v[i+k]] += 1;
        }

        max_k = largest.top();
        while( freq[max_k] == 0 && largest.size() != 0 ){
            largest.pop();
            max_k = largest.top();
        }
        //printf("%d\n", max_k);

        if( v[i] < max_k ) out.push_back(1);
        else out.push_back(0);
    }

    for( int i = 0; i < n; i ++){
        if( out[i] == 1 ) printf("y");
        else printf("n");
    }
    printf("\n" );



    return 0;
}
