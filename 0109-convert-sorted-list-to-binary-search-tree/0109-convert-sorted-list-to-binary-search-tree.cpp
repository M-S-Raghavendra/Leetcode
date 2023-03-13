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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        vector<int> v;
        for(auto cur=head;cur!=NULL;cur = cur->next)
            v.push_back(cur->val);
                
        int left = 0, right = v.size()-1;
        return f(v,left,right);
    }
    
    TreeNode* f(vector<int> &v, int l , int r)
    {
        if(l <= r)
        {
            int m = (l+r)/2;
            TreeNode* temp = new TreeNode(v[m]);
            
            temp->left = f(v,l,m-1);
            temp->right = f(v,m+1,r);
            
            return temp;
        }
        return NULL;
    }
};