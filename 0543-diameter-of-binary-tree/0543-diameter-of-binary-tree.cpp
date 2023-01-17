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
    int diameterOfBinaryTree(TreeNode* root) {
        return f(root);
    }
    
    int f(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left + right, max(f(root->left), f(root->right)));
    }
    
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return 1 + max(height(root->left),height(root->right));
    }
};