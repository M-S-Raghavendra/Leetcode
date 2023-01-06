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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int m = lists.size();
        
        if(m == 0) return NULL;
        if(m == 1) return lists[0];
        
        ListNode* head = NULL;
        
        head = merge(lists[0],lists[1]);
        
        for(int i=2;i<m;i++)
        {
            head = merge(head,lists[i]);
        }
        
        return head;
    }
    
    ListNode* merge(ListNode* a, ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;
        
        ListNode* dummy = new ListNode(0);
        ListNode* head, *tail;
        head = tail = dummy;
        
        while(a != NULL and b != NULL)
        {
            if(a->val <= b->val)
            {
                tail->next = a; 
                tail = tail->next;
                a = a->next;
            }
            else {
                tail->next = b;
                tail = tail->next;
                b = b->next;
            }
        }
        
        if(a)
            tail->next = a;
        if(b)
            tail->next = b;
        
        return head->next;
    }
};