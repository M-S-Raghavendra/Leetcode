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
        ListNode* h1, *h2;
        h1 = reverse(l1);
        h2 = reverse(l2);
        ListNode* p = h1, *q = h2;
        int d, sum = 0, carry = 0;
        ListNode* res = NULL;
        
        while(p and q)
        {
            sum = p->val + q->val + carry;
            d = sum%10;
            carry = sum/10;
            res = addtofront(res,d);
            p=p->next;
            q=q->next;
        }
        while(p)
        {
            sum = p->val + carry;
            d = sum%10;
            carry = sum/10;
            res = addtofront(res,d);
            p=p->next;
        }
        while(q)
        {
            sum = q->val + carry;
            d = sum%10;
            carry = sum/10;
            res = addtofront(res,d);
            q=q->next;
        }
        
        if(carry)
            res = addtofront(res,carry);
        
        return res;
    }
    
    ListNode* reverse(ListNode* h)
    {
        ListNode* cur=h, *prev=NULL, *next;
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    
    ListNode* addtofront(ListNode* res, int d)
    {
        ListNode* node = new ListNode(d);
        if(res == NULL) return node;
        node->next = res;
        return node;
    }
};