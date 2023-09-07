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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int cnt = 0;
        while(cur)
        {
            cnt++;
            cur = cur->next;
        }
        
        int c = cnt/k;
        int mod = cnt % k;
        vector<ListNode*> ans;
        
        cur = head;
        ListNode* prev = NULL;
        while(cur)
        {
            if(cnt < c)
            {
                ans.push_back(cur);
                break;
            }
            ListNode* start = cur;
            for(int i=0;i<c;i++)
            {
                prev = cur;
                cur = cur->next, cnt--;
            }
            
            if(cur and mod) {
                prev = cur;
                cur = cur->next;
                mod--, cnt--;
            }
            
            prev->next = NULL;
            ans.push_back(start);
        }
        
        while(ans.size() < k)
            ans.push_back(NULL);
        
        return ans;
    }
};