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
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        f(root,cnt);
        return cnt;
    }
    
    pair<int,int> f(TreeNode* root, int &cnt)
    {
        int sum = 0;
        if(root == NULL)
            return {0,sum};
        if(root->left == NULL and root->right == NULL)
        {
            sum += root->val;
            cnt++;
            return (pair<int,int>){1,sum};
        }
        
        int n = 1;
        auto x = f(root->left,cnt);
        auto y = f(root->right,cnt);
        
        n += x.first + y.first;
        sum += x.second + y.second;
        sum += root->val;
        
        int avg = sum/n;
        if(avg == root->val)
            cnt++;
        
        return (pair<int,int>){n,sum};
    }
};