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
private:
    int ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        f(root,0);
        return ans;
    }
    
    void f(TreeNode* root, int cur)
    {
        if(root == NULL)
            return ;
        if(root->left == NULL and root->right == NULL)
        {
            cur = (cur*10) + root->val;
            ans += cur;
            return ;
        }
        
        f(root->left,(cur*10) + root->val);
        f(root->right,(cur*10) + root->val);
    }
};