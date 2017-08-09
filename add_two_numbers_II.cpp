/*
 * LeetCode 445 Medium 26.6k/57.9k
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

 * Example:

 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pre = NULL;
        ListNode *middle = l1;
        ListNode *after;
        while(middle){
            after = middle->next;
            middle->next = pre;
            pre = middle;
            middle = after;
        }
        l1 = pre;
        pre = NULL;
        middle = l2;
        while(middle){
            after = middle->next;
            middle->next = pre;
            pre = middle;
            middle = after;
        }
        l2 = pre;
        ListNode* before = NULL;
        int carry = 0;
        while(l1||l2||carry){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* p = new ListNode(sum);
            p->next = before;
            before = p;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return before;
    }
};
