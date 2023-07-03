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
    ListNode* f(ListNode* head)
    {
        if(head == NULL or head->next == NULL or head->next->next == NULL)
            return head;
        
        ListNode* prev = NULL, *tail = head;
        while(tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        
        ListNode* nextHead = head->next;
        
        prev->next = NULL;
        head->next = tail;
        tail->next = f(nextHead);
        
        return head;
    }
    
    void reorderList(ListNode* head) {
        f(head);
    }
};