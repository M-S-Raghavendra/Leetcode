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
    // void solve(TreeNode* root, vector<int>& ans)
    // {
    //     if(root != NULL)
    //     {
    //         ans.push_back(root->val);
    //         solve(root->left,ans);
    //         solve(root->right,ans);
    //     }
    // }
    
    vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         solve(root,ans);
//         return ans;
        if(root == NULL)
            return {};
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> ans;        
        
        while(cur != NULL or !s.empty())
        {
            while(cur != NULL)
            {
                ans.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();  s.pop();
            cur = cur->right;
        }
        
        return ans;
    }
};