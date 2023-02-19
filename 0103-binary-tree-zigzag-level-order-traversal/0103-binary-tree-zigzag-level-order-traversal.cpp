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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};

        stack<TreeNode*> s1,s2;
        vector<vector<int>> ans;
        bool level = true;

        s1.push(root);

        while(!s1.empty() or !s2.empty())
        {
            vector<int> row;

            if(level)
            {
                int count = s1.size();

                for(int i=0;i<count;i++)
                {
                    TreeNode* cur = s1.top();
                    s1.pop();
                    row.push_back(cur->val);

                    if(cur->left) s2.push(cur->left);
                    if(cur->right) s2.push(cur->right);
                }
            }
            else
            {
                int count = s2.size();

                for(int i=0;i<count;i++)
                {
                    TreeNode* cur = s2.top();
                    s2.pop();
                    row.push_back(cur->val);

                    if(cur->right) s1.push(cur->right);
                    if(cur->left) s1.push(cur->left);
                }
            }
            
            level = !level;
            ans.push_back(row);
        }

        return ans;
    }
};