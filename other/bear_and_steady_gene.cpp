/*Problem discription can be found at https://www.hackerrank.com/challenges/bear-and-steady-gene
  Algorithm idea comes from user @jeffreyeffendy_1 posted about a year ago.
  The central idea of O(N) algorithm is to find out a way to iterate through the string such that the appearance of letter is monotonic.*/


#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool isvalid(map<char, int>& m, int l){
    if(m['G'] <= l && m['A'] <= l && m['C'] <= l && m['T'] <= l){
        return true;
    }
    else return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int len;
    int min_T = 0;
    string gene;
    cin >> len >> gene;
    map<char, int> m;
    m['A'] = 0;
    m['C'] = 0;
    m['T'] = 0;
    m['G'] = 0;
    
    for (int i = len - 1; i >= 0; i--){
        m[gene[i]] ++;
        if(!isvalid(m, len/4)){
            min_T = i;
            break;
        }
    }
    
    
    int sublen = min_T;
    for (int i = 0; min_T < (len -1) && i <= min_T; i++){
        m[gene[i]] ++;
        while(!isvalid(m, len/4) && min_T < (len -1)){
            m[gene[min_T]] --;
            min_T ++;
        }
        if(!isvalid(m, len/4)) break;
        if(sublen > (min_T - i -1) && (min_T -i -1) > 0) sublen = min_T - i -1;
    }
    
    cout << sublen;
    return 0;
}
