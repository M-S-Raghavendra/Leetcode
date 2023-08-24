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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int cnt = 0;
        
        while(cur)
        {
            cnt++;
            cur = cur->next;
        }
        
        return f(head,cnt,k);
    }
    
    ListNode* f(ListNode* head, int cnt, int k)
    {
        if(head == NULL) return head;
        
        if(cnt < k)
            return head;
        
        ListNode* prev = NULL, *cur = head, *next;
        for(int i=0;i<k;i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head->next = f(cur,cnt-k,k);
        
        return prev;
    }
};