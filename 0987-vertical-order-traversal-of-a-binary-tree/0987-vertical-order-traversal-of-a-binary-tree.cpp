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
private:
    void vot(TreeNode* root, map<int,vector<pair<int,int>>> &m, int r, int c)
    {
        if(root == NULL)
            return;
        
        m[c].push_back({r,root->val});
        
        vot(root->left, m, r+1,c-1);
        vot(root->right, m, r+1, c+1);
    }
    
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first < b.first)
            return true;
        else if(a.first == b.first)        
            return a.second < b.second;
        else return false;
    }
    
public:    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> m;
        vot(root,m,0,0);
        
        for(auto x:m)
        {
            vector<int> v;
            vector<pair<int,int>> temp = x.second;
            sort(temp.begin(),temp.end(),comp);
            
            for(auto y:temp)
                v.push_back(y.second);
            
            ans.push_back(v);
        }
        
        return ans;
    }
};