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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> m1;
        unordered_map<TreeNode*,TreeNode*> m2;
        TreeNode* root = NULL;
        
        for(int i=0;i<descriptions.size();i++)
        {
            int par = descriptions[i][0];
            int ch = descriptions[i][1];
            int isleft = descriptions[i][2];
            
            if(m1.find(par) == m1.end())
            {
                TreeNode* p = new TreeNode(par);
                m1.insert({par,p});
            }
            
            if(m1.find(ch) == m1.end())
            {
                 TreeNode* c = new TreeNode(ch);
                 m1.insert({ch,c});
            }
            
            TreeNode* u = m1[par];
            TreeNode* d = m1[ch];

            m2.insert({d,u});
            
            if(isleft)
            {
                u->left = d;
            }
            else
            {
                u->right = d;
            }
        }
        
        for(auto x:descriptions)
        {
            if(m2.find(m1[x[0]]) == m2.end())
                return m1[x[0]];
        }
        
        return root;
    }
};