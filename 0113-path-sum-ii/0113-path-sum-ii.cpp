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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> ans;
        vector<int> path;
        f(root,targetSum,path,ans);
        return ans;
    }
    void f(TreeNode* root, int tar, vector<int> &path, vector<vector<int>> &ans)
    {
        if(root)
        {
            path.push_back(root->val);
            
            if(root->left == NULL and root->right == NULL and tar == root->val)
            {
                ans.push_back(path);
            }
                        
            f(root->left,tar-root->val,path,ans);
            f(root->right,tar-root->val,path,ans);
            path.pop_back();
        }
    }
};