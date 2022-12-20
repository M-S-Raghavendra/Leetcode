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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL or head->next==NULL)
            return head;
        
        ListNode* lh, *lt, *gh, *gt;
        lh = lt = gh = gt = NULL;
        
        for(ListNode* cur=head;cur!=NULL;cur=cur->next)
        {
            if(cur->val < x)
            {
                if(lh == NULL)
                    lh = lt = cur;
                else
                {
                    lt->next = cur;
                    lt = lt->next;
                }
            }
            else {
                if(gh == NULL)
                    gh = gt = cur;
                else {
                    gt->next = cur;
                    gt = gt->next;
                }
            }
        }
        
        if(lh == NULL) return gh;
        if(gh == NULL) return lh;
        
        gt->next = NULL;
        lt->next = gh;
        
        return lh;
    }
};