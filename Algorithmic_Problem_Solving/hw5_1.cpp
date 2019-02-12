#define MAXNODES 300000 + 1
#include <iostream>
#include <string.h>
using namespace std;

int trieSize = 0;
class TrieNode {
public:
    int next[26], numEndNodes, max_ind, self_max_ind, max_freq;
    TrieNode(){
        numEndNodes = 0;
        max_ind = -1;
        max_freq = -1;
        self_max_ind = 0;
        memset(next, 0, sizeof(next));
    }
};

TrieNode nodes[MAXNODES];

int add(int k, int strIndex, string& str, int freq){
    if( str[strIndex] == 0 ){
        //printf("%s %d %d\n", str.c_str(), strIndex, k);
        nodes[k].numEndNodes += freq;
        if( nodes[k].numEndNodes >= nodes[k].max_freq ){
            nodes[k].self_max_ind = -1; // itself is the most frequent
        }
        return k;
    }
    char c = str[strIndex];
    int t = c - 'a';
    if( nodes[k].next[t] == 0 ){
        nodes[k].next[t] = ++trieSize;
        nodes[trieSize] = TrieNode();
    }
    if( freq > nodes[k].max_freq ){
        nodes[k].max_freq = freq;
        nodes[k].max_ind = t;
    }
    else if( freq == nodes[k].max_freq){
        if( t < nodes[k].max_ind ) nodes[k].max_ind = t;
    }

    if( freq > nodes[k].numEndNodes ) nodes[k].self_max_ind = 0; // itself no longer the most frequent

    return nodes[k].next[t];
}

/*
int preprocess(int k, TrieNode* nodes){
    int max_freq = -1;
    int max_ind = -1;
    int this_freq = -1;

    for( int i = 0; i < 26; i++ ){
        if( nodes[k].next[i] != 0 ){
            this_freq = preprocess(nodes[k].next[i], nodes);
            if( this_freq > max_freq ){
                max_freq = this_freq;
                max_ind = i;
            }
        }
    }
    if( nodes[k].numEndNodes != 0 ){
        if( nodes[k].numEndNodes >= max_freq ){
            max_freq = nodes[k].numEndNodes;
            nodes[k].self_max_ind = -1;
        }
    }
    nodes[k].max_ind = max_ind;
    return max_freq;
}
*/

int findLast(int k, int strIndex, string& s, TrieNode* nodes){
    //printf("%s %d\n", s.c_str(), k);
    if( s[strIndex] == '#' ) return k;
    if( nodes[k].next[ s[strIndex] - 'a' ] == 0 ) return -1;
    return findLast(nodes[k].next[ s[strIndex] - 'a' ], strIndex + 1, s, nodes);
}

void findMostFrequent(int k){
    //printf("%d\n", k);
    int next_k = nodes[k].next[nodes[k].max_ind];
    if(nodes[k].max_ind != -1 && nodes[k].self_max_ind == 0){
        printf("%c", 'a' + nodes[k].max_ind);
        findMostFrequent(next_k);
    }

    else return;
}

int main(){
    int n, freq, q;
    string s;
    scanf("%d\n", &n);

    for( int i = 0; i < n; i++){
        cin >> s >> freq;
        int k =0;
        for( int j = 0; j <= s.size(); j++){
            k = add(k , j, s, freq);
        }

    }

    /*
    for( int i = 0; i < 26; i++){
        if( nodes[2].next[i] !=0 ) printf("%d %d\n", i, nodes[2].next[i]);
    }
    */

    //printf("%d %d %d\n", nodes[0].max_ind, nodes[0].max_freq, nodes[0].next[nodes[0].max_ind]);

    cin >> q;
    for( int i = 0; i < q; i++ ){
        cin >> s;
        int last = findLast(0, 0, s, nodes);
        if( s[s.size()-1] == '#' ){
            printf("%s", s.substr(0, s.size()-1).c_str());
            //printf("last %d\n", last);
            if( last != -1){
                if(  nodes[last].numEndNodes != 0 ){
                    // itself is a word in lexicon
                    if(nodes[last].max_ind != -1 ){
                        //printf("h\n" );
                        int next_k = nodes[last].next[nodes[last].max_ind];
                        printf("%c", 'a' + nodes[last].max_ind);
                        findMostFrequent(next_k);
                    }
                }
                else findMostFrequent(last);
            }
        }
        else{
            printf("%s", s.c_str());
        }

        printf("\n" );
    }
}
