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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(i == count-1)
                    ans.push_back(t->val);
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        
        return ans;
    }
};