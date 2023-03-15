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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        
        while(!q.empty())
        {
            int cnt = q.size();
            bool gap = false, check = false;
            
            if((1<<l) != cnt)
                check = true;
            
            for(int i=0;i<cnt;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left)
                {
                    if(gap) return false;
                    q.push(t->left);
                }
                else if(!gap) 
                    gap = true;
                
                if(t->right)
                {
                    if(gap) return false;
                    q.push(t->right);
                }
                else if(!gap) 
                    gap = true;
            }
            
            if(check)
            {
                if(!q.empty()) return false;
            }
            l++;
        }
        
        return true;
    }
};