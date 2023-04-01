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
    int deepestLeavesSum(TreeNode* root) {        
        int sum;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            sum = 0;
            for(int i=0;i<count;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                sum += t->val;
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        
        return sum;
    }
};