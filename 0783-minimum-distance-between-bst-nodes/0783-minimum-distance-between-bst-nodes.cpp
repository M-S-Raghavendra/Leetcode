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
    int ans = INT_MAX, prev = -1;
    
    int minDiffInBST(TreeNode* root) {
        return f(root);
        // return ans;
    }
    
    int f(TreeNode* root)
    {
        if(root->left != NULL) f(root->left);
        if(prev >= 0)
            ans = min(ans,abs(root->val-prev));
        prev = root->val;
        if(root->right != NULL) f(root->right);
        return ans;
    }
    
//     int f(TreeNode* root, int &ans)
//     {
//         if(root)
//         {
//             sub(root->left,ans,root->val);
//             sub(root->right,ans,root->val);
//             f(root->left,ans);
//             f(root->right,ans);
//         }
//         return 1e9;
//     }
    
//     int sub(TreeNode* root, int &ans, int &top)
//     {
//         if(root)
//         {
//             ans = min(ans,abs((root->val)-top));
//             sub(root->left,ans,top);
//             sub(root->right,ans,top);
//         }
//         return 1e9;
//     }
};