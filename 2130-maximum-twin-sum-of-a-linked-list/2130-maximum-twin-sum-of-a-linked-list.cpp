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
private:
    ListNode* reverseList(ListNode* h)
    {
        ListNode* prev = NULL, *next;
        
        while(h)
        {
            next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }
        
        return prev;
    }
    
public:
    int pairSum(ListNode* head) {
        ListNode* slow, *fast;
        slow = fast = head;
        int ans = 0;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* newhead = reverseList(slow);
        ListNode* cur = head;
        
        while(newhead)
        {
            ans = max(ans, cur->val + newhead->val);
            cur = cur->next;
            newhead = newhead->next;
        }
        
        return ans;
        
//         stack<int> s;
//         int cnt = 0;
        
//         for(ListNode* cur=head;cur!=NULL;cur=cur->next)
//             cnt++;
//         int temp = cnt/2;
//         ListNode* cur = head;
//         while(temp--)
//         {
//             s.push(cur->val);
//             cur = cur->next;
//         }
        
//         int ans = 0;
        
//         while(cur)
//         {
//             int top = s.top();
//             s.pop();
//             ans = max(ans,top + cur->val);
//             cur = cur->next;
//         }
        
//         return ans;
    }
};