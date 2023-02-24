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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        f(head,ans,s);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void f(ListNode* head, vector<int>& ans, stack<int> &s)
    {
        if(head == NULL)
            return ;
        
        f(head->next,ans,s);
        
        if(!s.empty() and head->val < s.top())
        {
            ans.push_back(s.top());
        }
        else {
            while(!s.empty() and head->val >= s.top())
                s.pop();
            if(s.empty())
                ans.push_back(0);
            else
                ans.push_back(s.top());
        }
        s.push(head->val);
    }
};