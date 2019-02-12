#include <iostream>
#include <map>
#include <bitset>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class TrieNode{
public:
    TrieNode* next[2];
    //int numEndNodes = 0;

    TrieNode(){
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

TrieNode* add(TrieNode* node, int ind, string& num){
    //printf("adding %s %d %c\n", num.c_str(), ind, num[ind] );

    if( num[ind] == '0' ){
        if( node->next[0] == nullptr ){
            node->next[0] = new TrieNode();
        }
        return node->next[0];
    }
    else if( num[ind] == '1' ){

        if( node->next[1] == nullptr ){
            node->next[1] = new TrieNode();
        }
        return node->next[1];
    }
    else return nullptr;
}

TrieNode* findComplement(TrieNode* node, int ind, string& num, string& com){
    if( num[ind] == '0' ){
        if( node->next[1] != nullptr ){
            com += '1';
            return node->next[1];
        }
        else if( node->next[0] != nullptr ){
            com += '0';
            return node->next[0];
        }
    }
    else if( num[ind] == '1' ){
        if( node->next[0] != nullptr ){
            com += '0';
            return node->next[0];
        }
        else if( node->next[1] != nullptr ){
            com += '1';
            return node->next[1];
        }
    }
}

int main(){
    int n, a, b, w;
    cin >> n;
    map<int, int> chain;

    for( int i =0; i < n; i++ ){
        cin >> a >> b >> w;
        chain[min(a, b)] = w;
    }

    TrieNode* root = new TrieNode();
    int cur;
    TrieNode* last = root;
    vector<string> complements;

    // add zero
    string binary = bitset<30>(0).to_string();
    for( int i = 0; i < 30 ; i++ ){
        last = add( last, i, binary );
    }

    for( auto it = chain.begin(); it != chain.end(); it ++ ){
        last = root;
        if( it != chain.begin()) cur = cur ^ it->second;
        else cur = it->second;

        binary = bitset<30>(cur).to_string();
        complements.push_back(binary);
        //printf("%d %s\n", cur, binary.c_str());

        for( int i = 0; i < 30 ; i++ ){
            last = add( last, i, binary );
        }
        //last->numEndNodes += 1;
    }

    unsigned long max_xor = 0;
    string com;
    for(auto it = complements.begin(); it != complements.end(); it++){
        string binary = *it;
        com.clear();
        last = root;
        for( int i = 0; i < 30 ; i++ ){
            last = findComplement( last, i, binary, com );
        }
        unsigned long com_long = bitset<30>(com).to_ulong();
        unsigned long cur_long = bitset<30>(binary).to_ulong();
        if( (com_long ^ cur_long) > max_xor) max_xor = (com_long ^ cur_long);
    }
    printf("%lu\n", max_xor);
    return 0;
}
