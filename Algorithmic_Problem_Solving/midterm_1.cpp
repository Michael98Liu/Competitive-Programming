#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_set>
#include <string.h>

using namespace std;

string swap(string& s, int i, int j){
    char word[10];

    memset(word, 0, 10);
    for( int k = 0; k < s.size(); k++){
        word[k] = s.c_str()[k];
    }

    char temp = word[i];
    word[i] = word[j];
    word[j] = temp;
    return string(word);
}

int main(){
    int n,q;
    scanf("%d\n", &n);
    string word;
    int num;

    unordered_set<string> dict;
    for( int i = 0; i < n; i++ ){
        cin >> word;
        dict.insert(word);
    }

    scanf("%d\n", &q);

    for( int i = 0; i< q; i++){
        cin >> word;
        num = 0;
        for( int j = 0; j< word.size() - 1; j++ ){
            word = swap(word, j, j+1);
            auto it = dict.find(word);
            if( it != dict.end() ) num ++;
            word = swap(word, j, j+1);
        }

        printf("%d\n", num);
    }




    return 0;
}
