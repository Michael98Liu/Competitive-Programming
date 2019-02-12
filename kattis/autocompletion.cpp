#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class TrieNode{
public:
    int numEndNodes; // store the number of words that emanates from here, including itself
    bool isEnd;
    TrieNode* next[26];
    char letter;

    TrieNode(int i){
        memset(next, 0, 26);
        numEndNodes = 0;
        isEnd = false;
        letter = 'a'+i;
    }

};

void addNode(TrieNode* rootNode, string& word, int k){
    rootNode->numEndNodes += 1;

    if( k == word.size() ){
        rootNode->isEnd = true;
        return;
    }

    char letter = word[k];
    int ind = letter - 97;

    if( rootNode->next[ind] == nullptr ){
        TrieNode* newNode = new TrieNode(ind);
        rootNode->next[ind] = newNode;
    }

    addNode(rootNode->next[ind], word, k + 1);
    return;
}

TrieNode* findLast(TrieNode* rootNode, string& word, int k){
    if( k == word.size() ){
        return rootNode;
    }

    char letter = word[k];
    int ind = letter - 97;

    TrieNode* wordNode = rootNode->next[ind];
    return findLast(wordNode, word, k+1);
}

void complete(TrieNode* rootNode, int hash, bool first, string& result ){
    int count = 0;
    int i = 0;
    printf("%c %d\n", rootNode->letter, hash);

    if( !first ) result += rootNode->letter;

    if( hash == 1 && first ){
        while( rootNode->next[i] == nullptr ){
            i ++;
        }
        complete(rootNode->next[i], hash, false, result);
        return;
    }

    if( hash == 1 && rootNode->isEnd ){
        return;
    }

    i = 0;
    int notempty = 0;
    if( hash > rootNode->numEndNodes ) hash = hash % rootNode->numEndNodes;
    printf("%d %d\n", hash, rootNode->numEndNodes);

    while( hash - count > 0 ){
        if( rootNode->next[i] != nullptr){
            notempty ++;
            count += rootNode->next[i]->numEndNodes;
        }
        i ++;
    }

    count -= rootNode->next[i-1]->numEndNodes;
    if( notempty == 1 ){
        if( rootNode->isEnd ) hash -= 1;
    }
    else hash -= count;

    complete(rootNode->next[i-1], hash, false, result);
    return;
}

int main(){
    int n, q;
    scanf("%d\n", &n);

    string s;
    TrieNode* rootNode = new TrieNode(-1);

    for( int i = 0; i < n; i++ ){
        cin >> s;

        addNode(rootNode, s, 0);
    }

    int hashCount;
    scanf("%d\n", &q);

    for( int i = 0; i < q; i++ ){
        hashCount = 0;
        string prehash;
        string afterhash;

        cin >> s;
        afterhash = s;
        int h = s.find('#');

        if( h != string::npos ){
            while( h != string::npos && afterhash.size() != 0){
                hashCount = 0;
                string result;

                prehash += afterhash.substr(0, h);

                // get number of hash
                while( afterhash[h] == '#' ){
                    hashCount ++;
                    h ++;
                }
                afterhash = afterhash.substr(h, afterhash.size());
                h = afterhash.find('#');

                TrieNode* lastNode = findLast(rootNode, prehash, 0);
                complete(lastNode, hashCount, true, result);
                prehash += result;
            }
            prehash += afterhash;
            printf("%s\n", prehash.c_str());
        }
        else printf("%s\n", s.c_str());

    }
}
