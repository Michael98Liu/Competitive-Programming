#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, num;
    scanf("%d\n", &n);
    vector<int> v;

    for(int i =0; i < n; i++ ){
        cin >> num;
        v.push_back(num);
    }

    vector<int> stack;
    vector<int> l;
    vector<int> r;

    stack.push_back(0);
    for(int i =0; i < n; i++ ){
        while( stack.size() != 0 && v[stack.back()] <= v[i]){
            stack.pop_back();
        }
        if( stack.size() != 0) l.push_back(stack.back());
        else l.push_back(0);
        stack.push_back(i);
    }

    stack.clear();
    stack.push_back(n-1);
    for(int i =n-1; i >=0; i-- ){
        while( stack.size() != 0 && v[stack.back()] <= v[i]){
            stack.pop_back();
        }
        if( stack.size() != 0) l.push_back(stack.back());
        else r.push_back(0);
        stack.push_back(i);
    }

    for(int i =0; i < n; i++ ){
        printf("%d\n", r[i]);
    }

}
