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
    string tree2str(TreeNode* root) {
        string ans = "";
        
        preorder(root,ans);
        return ans;
    }
    
    void preorder(TreeNode* root, string &ans)
    {
        if(root)
        {
            ans += to_string(root->val);
            if(root->left == NULL and root->right == NULL)
                return;
            
            ans += "(";
            preorder(root->left,ans);
            ans += ")";
            
            if(root->right == NULL) return;
            ans += "(";
            preorder(root->right,ans);
            ans += ")";
        }
    }
};