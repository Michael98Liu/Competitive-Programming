/* LeetCode 5 Medium 219.5k/872.6k
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0;
        int m = 1;
        int r = 2;
        int longest = 0;
        string result;
        bool exist = 0;
        
        while( r < s.size()){
            if( s[l] == s[m] ){
                //cout << l << ' ' << m << endl;
                int d = 0;
                while( s[l-d] == s[m+d] && (l-d) >=0 && (m+d) < s.size()){
                    d++;
                }
                d --;
                if( longest < 2*(d+1) ){
                    longest = 2*(d+1);
                    result = s.substr(l-d, 2*d + 2);
                }
                exist = 1;
            }
            if( s[m] == s[r] ){
                int d = 0;
                while( s[m-d] == s[r+d] && (m-d) >=0 && (r+d) < s.size()){
                    d++;
                }
                d --;
                if( longest < 2*(d+1) ){
                    longest = 2*(d+1);
                    result = s.substr(m-d, 2*d + 2);
                }
                exist = 1;
            }
            if( s[l] == s[r] ){
                int d = 0;
                while( s[l-d] == s[r +d] && (l-d) >= 0 && (r+d) < s.size()){
                    d++;
                }
                d --;
                if( longest < (2*d + 3) ){
                    longest = 2*d + 3;
                    result = s.substr(l-d, (2*d +3));
                }
                exist = 1;
            }
            
            l ++;
            r ++;
            m ++;
        }
        if( !exist ) result = s[0];
        
        if(s.size() == 2){
            if( s[0] == s[1] ){
                longest = 2;
                result = s;
            }
        }
        else if( s.size() == 1 ){
            longest = 1;
            result = s;
        }
        
        return result;
    }
};
