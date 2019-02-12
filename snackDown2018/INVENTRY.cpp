#include <iostream>
#include <string>
using namespace std;

int moveRight(string& s, int i){
    int move = 0;
    if( i >= s.size() - 2 ) return -1;
    if( s[i+1] == '#' ){
        int ret = moveRight(s, i+1);
        if( ret == -1 ) return -1;
        else move += ret;
    }
    if( s[i+1] == '.' ){
        if( s[i+2] == '.' ){
            s[i+1] = '#';
            s[i] = '.';
            return move+1;
        }
    }



}

int moveLeft(string& s, int i){
    if( i >= s.size()-1 ) return -1;
    if( s[i+1] == '.' ){
        s[i-1] = '#';
        s[i] = '.';
        return 1;
    }
    if( s[i+1] == '#' ){
        int ret = moveRight(s, i+1);
        if( ret != -1 ){
            s[i-1] = '#';
            s[i] = '.';
            return ret +1;
        }
        else return -1
    }
}

int main(){
    int t;
    scanf("%d\n", &t);

    for( int case =0; case < t; case++){
        int n;
        string s;
        scanf("%d\n", &n);
        cin >> s;
        int i = 0;
        int move = 0;
        while( i < n ){
            if( s[i] == '.') i++;
            else if( s[i] == '#' ){
                if( i>0 && s[i-1] == '.' ){
                    int ret = moveLeft(s, i);
                    if( ret != -1 ) move += ret;
                    else{
                        printf("-1\n" );
                        return 0;
                    }
                }
            }
        }
    }
}
