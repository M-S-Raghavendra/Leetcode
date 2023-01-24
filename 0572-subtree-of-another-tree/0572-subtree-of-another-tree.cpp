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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root, subRoot);
    }
    
    bool f(TreeNode* root, TreeNode* subroot)
    {
        if(root)
        {
            if(root->val == subroot->val)
            {
                if(same(root,subroot))
                    return true;
            }
            return f(root->left,subroot) or f(root->right,subroot);
        }
        return false;
    }
    
    bool same(TreeNode* root, TreeNode* subroot)
    {
        if(root == NULL and subroot == NULL)
            return true;
        if(root == NULL or subroot == NULL)
            return false;
        
        return ((root->val == subroot->val) and same(root->left,subroot->left) and same(root->right,subroot->right));
    }
};
