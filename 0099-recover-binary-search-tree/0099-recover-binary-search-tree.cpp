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
    TreeNode* prev = NULL, *first = NULL, *second = NULL;
    
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return ;
        
        f(root);
        
        if(first and second)
        {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
    
    void f(TreeNode* root)
    {
        if(root == NULL)
            return ;
        
        f(root->left);
        
        if(prev and root->val < prev->val)
        {
            if(first == NULL)
            {
                first = prev;
                second = root;
            }
            else
                second = root;
        }
        prev = root;
        
        f(root->right);
    }
};