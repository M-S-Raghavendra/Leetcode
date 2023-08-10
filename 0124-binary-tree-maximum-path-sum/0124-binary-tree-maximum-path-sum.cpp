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
    int f(TreeNode* root, int &ans)
    {
        if(root == NULL)
            return 0;
        
        int left = f(root->left,ans);
        int right = f(root->right,ans);
        
        ans = max(ans, max(root->val, left + right + root->val));
        
        int ret = max(root->val, max(left, right) + root->val);
        ans = max(ans, ret);
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        f(root,ans);
        return ans;
    }
};