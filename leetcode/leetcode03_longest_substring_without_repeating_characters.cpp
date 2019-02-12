/*
 * LeetCode 3 324.2k/1.3M
 * Given a string, find the length of the longest substring without repeating characters.

 * Examples:

 * Given "abcabcbb", the answer is "abc", which the length is 3.

 * Given "bbbbb", the answer is "b", with the length of 1.

 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> store;
        vector<char>::iterator it;
        int front = 1;
        int back = 0;
        int longgest = 0;
        store.push_back(s[back]);
        while(front < s.size() && back < s.size()){
            it = find(store.begin(), store.end(), s[front]);
            while( it == store.end() && front < s.size()){
                store.push_back(s[front]);
                front ++;
                it = find(store.begin(), store.end(), s[front]);
            }
            longgest = longgest > store.size() ? longgest : store.size();
            cout << s[back] <<' '<< s[front] << endl;
            cout << store.size() << endl;
            cout << longgest << endl;
            while( s[back] != s[front] && back < s.size() - 1){
                it = find(store.begin(), store.end(), s[back]);
                store.erase(it);
                back ++;
            }
            it = find(store.begin(), store.end(), s[back]);
            store.erase(it);
            back ++;
        }
        if(s.size() == 1) longgest = 1;
        return longgest;
    }
};
