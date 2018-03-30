/*
 *Description:
 *You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 *Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *Output: 7 -> 0 -> 8
 
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
        ListNode head(0);
        ListNode* p = &head;
        int carry = 0;
        while(l1||l2||carry){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
            p->next = new ListNode(sum);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head.next;
    }
};

//My Original Lengthy Code
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num = 0;
        int carry = 0;
        int val = 0;
        ListNode node(0);
        ListNode* head = &node;
        ListNode* p = &node;
        while(l1 != NULL && l2 != NULL){
            num += carry;
            num += l1->val;
            num += l2->val;
            val = num %10;
            carry = (num-val)/10;
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
            num = 0;
        }
        while(l1 != NULL){
            num += carry;
            num += l1->val;
            val = num %10;
            carry = (num-val)/10;
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
            num = 0;
        }
        while(l2 != NULL){
            num += carry;
            num += l2->val;
            val = num %10;
            carry = (num-val)/10;
            p->next = new ListNode(val);
            p = p->next;
            l2 = l2->next;
            num = 0;
        }
        if(carry != 0){
            p->next = new ListNode(carry);
        }
        return node.next;
    }
};
*/
