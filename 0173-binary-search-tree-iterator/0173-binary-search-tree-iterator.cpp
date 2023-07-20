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
class BSTIterator {
private:
//     vector<int> nodes;
//     int n;
//     int index = -1;
    
//     void inorder(TreeNode* root) {
//         if(root) {
//             inorder(root->left);
//             nodes.push_back(root->val);
//             inorder(root->right);
//         }
//     }
    
    stack<TreeNode*> s;
    
    void pushPathNodes(TreeNode* node)
    {
        TreeNode* cur = node;
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushPathNodes(root);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushPathNodes(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */