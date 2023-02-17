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
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        f(root,ans);
        return ans;
    }
    
    int f(TreeNode* root, int &ans)
    {
        if(root)
        {
            sub(root->left,ans,root->val);
            sub(root->right,ans,root->val);
            f(root->left,ans);
            f(root->right,ans);
        }
        return 1e9;
    }
    
    int sub(TreeNode* root, int &ans, int &top)
    {
        if(root)
        {
            ans = min(ans,abs((root->val)-top));
            sub(root->left,ans,top);
            sub(root->right,ans,top);
        }
        return 1e9;
    }
};