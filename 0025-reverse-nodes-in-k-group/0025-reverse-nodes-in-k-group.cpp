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
    ListNode* f(ListNode* head, int k, int cnt)
    {
        if(head == NULL) 
            return head;
        
        if(cnt < k)
            return head;
        
        ListNode* cur = head, *prev = NULL, *next;
        for(int i=0;i<k and cur;i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        ListNode* newHead = f(cur,k,cnt-k);
        head->next = newHead;
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* cur = head;
        
        while(cur)
        {
            cnt++;
            cur = cur->next;
        }
        
        return f(head,k,cnt);
    }
};