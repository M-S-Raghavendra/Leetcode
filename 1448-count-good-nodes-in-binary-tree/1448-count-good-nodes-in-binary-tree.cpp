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
    int goodNodes(TreeNode* root) {
        return f(root, -100000);
    }
    
    int f(TreeNode* root, int maxi)
    {
        if(root == NULL)
            return 0;
        
        return (root->val >= maxi) + f(root->left, max(maxi,root->val)) + 
                                    f(root->right, max(maxi,root->val));
    }
};