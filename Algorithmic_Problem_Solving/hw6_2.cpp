#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <unordered_set>
#include <algorithm>
#include <string.h>
using namespace std;

int nChoosek( int n, int k ){
    /* code of combinatorial is from:
    https://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c */
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
    map<char, int> index;
    for( int i = 50; i <= 57; i++ ){
        index[char(i)] = i-50;
    }
    index['X'] = 8;
    index['J'] = 9;
    index['Q'] = 10;
    index['K'] = 11;
    index['A'] = 12;

    string cards("23456789XJQKA");

    int n, k;
    scanf("%d %d\n", &n, &k);

    string common, reaction;
    getline(cin, common);
    getline(cin, reaction);
    //printf("%s %s\n", common.c_str(), reaction.c_str());

    bitset<13> mask, mustHave;
    mask.set(); // optional cards
    mustHave.reset(); // all the cards that must have
    unordered_set<char> seen, notHave;
    int occur[13];

    for( int i =0; i < 13; i++ ){
        occur[i] = 4;
    }

    for( int i = 0; i < common.size(); i ++ ){
        occur[index[common[i]]] -= 1;

        if( reaction[i] == 'n' ){
            auto it = seen.find(common[i]);
            if( it != seen.end() ){
                printf("impossible\n");
                return 0;
            }
            //printf("%d\n", index[common[i]]);

            mask.reset(index[common[i]]); // cannot have this card
            notHave.insert(common[i]);
            seen.insert(common[i]);
        }
        else if( reaction[i] == 'y'){
            auto it = seen.find(common[i]);
            if( it == seen.end() ){
                mustHave.set(index[common[i]]);
                seen.insert(common[i]);
            }
            mask.reset(index[common[i]]);
        }

        if( mustHave.count() > k ){
            printf("impossible\n");
            return 0;
        }

        if( notHave.size()*4 > 52 - k ){
            printf("impossible\n");
            return 0;
        }
    }

    //printf("%s %s\n", mask.to_string().c_str(), mustHave.to_string().c_str());

    vector<int> mustHaveVec;
    // check must have card must at least have one left
    for( int i = 0; i < 13; i++){
        if( mustHave.test(i) ){
            if( occur[i] == 0 ){
                printf("impossible\n");
                return 0;
            }
            mustHaveVec.push_back(i);
            occur[i] -= 1;
        }
    }

    vector<int> pool;
    int limit = k - mustHaveVec.size(); // limit of occurances of each card
    int min_limit = 0;

    for( int i =0; i < 13; i++ ){
        //printf("%d\n", occur[i]);
        if( mustHave.test(i) || mask.test(i) ){
            min_limit = min(limit, occur[i]);

            for( int j = 0; j < min_limit; j++ ){
                pool.push_back(i);
            }
        }
    }
    //printf("pool size %lu\n", pool.size());
    vector< vector<int> > results;

    // selector vector
    vector<bool> v(pool.size());
    fill(v.end() - (k-mustHaveVec.size()), v.end(), true);

    vector<int> oneCase;
    vector<int> prev;

    do{
        for (int i = 0; i < v.size(); i++){
            if( v[i] ){
                oneCase.push_back(pool[i]);
            }
        }
        //oneCase.insert(oneCase.end(), mustHaveVec.begin(), mustHaveVec.end());
        //sort(oneCase.begin(), oneCase.end());

        results.push_back(oneCase);
        oneCase.clear();
    }while(next_permutation(v.begin(), v.end()));

    sort(results.begin(), results.end());
    auto it = results.begin();

    while(  it != results.end()){
        bool same = true;
        if( it == results.begin() ){
            prev = (*it);
            it ++;
        }
        if( it == results.end() ) break;

        for( int i=0; i < it->size(); i++ ){
            if( (*it)[i] != prev[i] ){
                same = false;
                break;
            }
        }
        if( same == true ) it = results.erase(it);
        else{
            prev = (*it);
            it ++;
        }
    }

    printf("%lu\n", results.size());
    for( auto it = results.begin(); it != results.end(); it ++){
        for( auto iit = it->begin(); iit != it->end(); iit++){
            printf("%c", cards[*iit]);
        }
        printf("\n" );
    }


    return 0;
}
