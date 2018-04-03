# https://leetcode.com/problems/longest-valid-parentheses/discuss/14133/My-DP-O(n)-solution-without-using-stack
# key: to indentify subproblem as the longest valid parentheses end at s[i]
# if s[i] == '(', longest[i] = 0, but basically it doesn't matter what to store in '(', only ')' matters
class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) > 1:
            longest = [0] * len(s)
            longest[0] = 0
            longest[1] = 2 if s[0] == '(' and s[1] == ')' else 0
            for i in range(2, len(s)):
                if s[i] == '(':
                    longest[i] = 0
                else:
                    if s[i-1] == '(':
                        longest[i] = longest[i-2] + 2
                    elif i-longest[i-1] -1 >=0:
                        if s[i-1] == ')' and s[i-longest[i-1] -1 ] == '(':
                            longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
                    else:
                        longest[i] = 0
            #print(longest)
            return max(longest)
        else:
            return 0
