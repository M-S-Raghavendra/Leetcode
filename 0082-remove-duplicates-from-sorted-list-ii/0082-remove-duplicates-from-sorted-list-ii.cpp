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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next == NULL)
            return head;
        
        ListNode* cur = head->next, *prev = head, *pp = NULL;
        
        while(cur)
        {
            int cnt = 0;
            while(cur and cur->val == prev->val)
            {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                cnt++;
            }
            if(cnt) {
                if(pp)
                    pp->next = cur;
                else
                    head = head->next;
                delete prev;
                prev = cur;
                if(cur)
                    cur = cur->next;
            }
            else {
                pp = prev;
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};