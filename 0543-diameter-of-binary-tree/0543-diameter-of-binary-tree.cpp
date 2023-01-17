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
        int ans = 0;
        h(root,ans);
        return ans;
    }
    
//     int f(TreeNode* root)
//     {
//         if(root == NULL)
//             return 0;
        
//         int left = h(root->left);
//         int right = h(root->right);
        
//         return max(left + right, max(f(root->left), f(root->right)));
//     }
    
    int h(TreeNode* root, int &ans)
    {
        if(root == NULL)
            return 0;
        int left = h(root->left,ans);
        int right = h(root->right,ans);
        
        int res = left + right;
        ans = max(ans,res);
        
        return 1 + max(left,right);
    }
};