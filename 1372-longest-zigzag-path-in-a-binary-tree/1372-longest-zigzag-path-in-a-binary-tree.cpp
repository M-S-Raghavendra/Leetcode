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
    int maxLen = 0;
    int longestZigZag(TreeNode* root) {
        f(root,true,0);
        f(root,false,0);
        return maxLen;
    }
    
    void f(TreeNode* root, bool isleft, int cnt)
    {
        if(root == NULL)
            return ;
        
        maxLen = max(maxLen,cnt);
        
        if(isleft)
        {
            f(root->left,false,cnt+1);
            f(root->right,true,1);
        }
        else {
            f(root->right,true,cnt+1);
            f(root->left,false,1);
        }
    }
};