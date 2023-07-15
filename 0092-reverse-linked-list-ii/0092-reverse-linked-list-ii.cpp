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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        for(int i=0;i<left-1;i++)
        {
            prev = cur;
            cur = cur->next;
        }
        
        if(cur == NULL)
            return head;
        
        ListNode* next;
        ListNode* leftRem = prev, *tail = cur;
        int l = right - left;
        
        for(int i=0;i<l;i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        next = cur->next;
        cur->next = prev;
        
        if(leftRem)
            leftRem->next = cur;
        else
            head = cur;
        tail->next = next;
        
        return head;
    }
};