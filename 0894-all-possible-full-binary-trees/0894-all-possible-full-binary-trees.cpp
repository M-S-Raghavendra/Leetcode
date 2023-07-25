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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 0)
            return {NULL};
        
        if(n % 2 == 0)
            return {};
        
        vector<TreeNode*> ans;
        
        for(int i=0;i<n;i++)
        {
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n-i-1);
            
            for(auto x:l)
            {
                for(auto y:r)
                {
                    TreeNode* newTree = new TreeNode(0,x,y);
                    ans.push_back(newTree);
                }
            }
        }
        
        return ans;
    }
};