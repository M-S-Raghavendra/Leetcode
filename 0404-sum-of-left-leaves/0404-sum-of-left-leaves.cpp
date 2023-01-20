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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        TreeNode* par = NULL;
        preorder(root,par,ans);
        return ans;
    }
    
    void preorder(TreeNode* root, TreeNode* par, int &ans)
    {
        if(root)
        {
            if(root->left == NULL and root->right == NULL)
            {
                if(par and par->left == root)
                    ans += root->val;
            }
            preorder(root->left,root,ans);
            preorder(root->right,root,ans);
        }
    }
};