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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, ans = 1;
        long long sum = root->val;
        long long cur = 0;
        
        while(!q.empty())
        {
            int count = q.size();
            cur = 0;
            for(int i=0;i<count;i++)
            {
                TreeNode* u = q.front();
                q.pop();
                cur += u->val;
                
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            
            if(cur > sum)
            {
                sum = cur;
                ans = level;
            }
            
            level++;
        }
        
        return ans;
    }
};