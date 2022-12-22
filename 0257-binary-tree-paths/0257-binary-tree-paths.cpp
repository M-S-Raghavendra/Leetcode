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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<string> ans;
        string s = "";
        f(root,s,ans);
        return ans;
    }
    
    void f(TreeNode* root, string s, vector<string> &ans)
    {        
        if(root)
        {
            if(!root->left and !root->right)
            {
                s += to_string(root->val);
                ans.push_back(s);
                return ; 
            }
            
            s += to_string(root->val) + "->";
            f(root->left,s,ans);
            f(root->right,s,ans);
        }
    }
};