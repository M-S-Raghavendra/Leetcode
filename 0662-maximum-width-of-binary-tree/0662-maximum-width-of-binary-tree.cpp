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
    int widthOfBinaryTree(TreeNode* root) {
        return f(root);
    }
    
    int f(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        long long mx = INT_MIN;
        
        while(!q.empty())
        {
            long long cnt = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            
            mx = max(mx, end-start+1);
            
            for(long long i=0;i<cnt;i++)
            {
                pair<TreeNode*,long long> p = q.front();
                q.pop();
                TreeNode* t = p.first;
                long long index = p.second;
                index -= start;
                
                if(t->left)
                    q.push({t->left,2*index});
                if(t->right)
                    q.push({t->right,2*index+1});
            }
        }
        
        return mx;
    }
};