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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        return f(1,n);
    }
    
    vector<TreeNode*> f(int s, int e)
    {
        if(s > e) return {};
        if(s == e) return {new TreeNode(s)};
        
        vector<TreeNode*> ans;
        for(int i=s;i<=e;i++)
        {
            vector<TreeNode*> left = f(s,i-1);
            vector<TreeNode*> right = f(i+1,e);
            
            if(left.empty())
                for(auto y:right)
                {
                    TreeNode* t = new TreeNode(i);
                    t->right = y;
                    ans.push_back(t);
                }
            if(right.empty())
                for(auto x:left)
                {
                    TreeNode* t = new TreeNode(i);
                    t->left = x;
                    ans.push_back(t);
                }
            
            for(auto x:left)
            {
                for(auto y:right)
                {
                    TreeNode* t = new TreeNode(i);
                    t->left = x;
                    t->right = y;
                    ans.push_back(t);
                }
            }
        }
        
        return ans;
    }
};