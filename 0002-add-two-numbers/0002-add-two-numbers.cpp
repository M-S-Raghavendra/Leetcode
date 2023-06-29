/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* p = l1, *q = l2;
        ListNode* res = NULL, *tail = NULL;
        int sum = 0, digit, carry = 0;
        ListNode* newnode;
        
        while(p and q)
        {
            sum = p->val + q->val + carry;
            digit = sum % 10;
            carry = sum/10;
            newnode = new ListNode(digit);
            if(res == NULL)
                res = tail = newnode;
            else {
                tail->next = newnode;
                tail = tail->next;
            }
            p = p->next;
            q = q->next;
        }
        
        while(p)
        {
            sum = p->val + carry;
            digit = sum % 10;
            carry = sum/10;
            newnode = new ListNode(digit);
            tail->next = newnode;
            tail = tail->next;
            p = p->next;
        }
        
        while(q)
        {
            sum = q->val + carry;
            digit = sum % 10;
            carry = sum/10;
            newnode = new ListNode(digit);
            tail->next = newnode;
            tail = tail->next;
            q = q->next;
        }
        
        if(carry)
        {
            newnode = new ListNode(carry);
            tail->next = newnode;
            tail = tail->next;
        }
        
        return res;
    }
};