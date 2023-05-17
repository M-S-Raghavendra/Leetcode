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
    int pairSum(ListNode* head) {
        stack<int> s;
        int cnt = 0;
        
        for(ListNode* cur=head;cur!=NULL;cur=cur->next)
            cnt++;
        int temp = cnt/2;
        ListNode* cur = head;
        while(temp--)
        {
            s.push(cur->val);
            cur = cur->next;
        }
        
        int ans = 0;
        
        while(cur)
        {
            int top = s.top();
            s.pop();
            ans = max(ans,top + cur->val);
            cur = cur->next;
        }
        
        return ans;
    }
};