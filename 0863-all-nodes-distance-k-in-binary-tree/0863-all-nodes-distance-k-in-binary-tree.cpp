/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*,TreeNode*> par;
    unordered_set<int> s;    
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* parent = NULL;
        vector<int> ans;
        
        preorder(root,target,parent);        
        f(target,ans,k);
        
        return ans;
    }
    
    void f(TreeNode* node, vector<int> &ans, int k)
    {
        if(node == NULL)
            return;
        
        if(s.find(node->val) != s.end())
            return;
        
        s.insert(node->val);
        
        if(k == 0) {
            ans.push_back(node->val);
            return;
        }
        
        // cout<<node->val<<" "<<par[node]<<" ";
        if(node->left)
            f(node->left,ans,k-1);
        if(node->right)
            f(node->right,ans,k-1);
        
        auto p = par[node];
        if(p)
            f(par[node],ans,k-1);
    }
    
    void preorder(TreeNode* root, TreeNode* target, TreeNode* parent)
    {
        if(root == NULL)
            return ;
        if(root == target)
        {
            par[root] = parent;
            return ;
        }
        
        par[root] = parent;
        preorder(root->left,target,root);
        preorder(root->right,target,root);
    }
};