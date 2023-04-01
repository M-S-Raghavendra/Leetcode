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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        f(root,sum);
        return sum;
    }
    
    void f(TreeNode* root, int &sum)
    {
        if(root == NULL)
            return ;
        
        if((root->val % 2) == 0)
        {
            sum += gc(root->left);
            sum += gc(root->right);
        }
        f(root->left,sum);
        f(root->right,sum);
    }
    
    int gc(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        if(root->left)
            ans += root->left->val;
        if(root->right)
            ans += root->right->val;
        
        return ans;
    }
};