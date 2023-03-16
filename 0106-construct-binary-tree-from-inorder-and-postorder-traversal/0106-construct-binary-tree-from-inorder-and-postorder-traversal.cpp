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
    int postind;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m.insert({inorder[i],i});
        postind = postorder.size()-1;
        return constructBT(postorder,0,postorder.size()-1,m);
    }
    
    TreeNode* constructBT(vector<int> &postorder, int l, int r, unordered_map<int,int> &m)
    {
        if(l > r)
            return NULL;
        
        int data = postorder[postind--];
        TreeNode* root = new TreeNode(data);
        
        //V.V.Imp - Call right and then only call left
        root->right = constructBT(postorder,m[data]+1,r,m);
        root->left = constructBT(postorder,l,m[data]-1,m);
        return root;
    }
};