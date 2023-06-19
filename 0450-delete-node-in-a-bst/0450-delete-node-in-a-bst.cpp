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
    TreeNode* getInorderSuccessor(TreeNode* node)
    {
        if(node == NULL)
            return node;
        TreeNode* cur = node->right;
        while(cur->left)
            cur = cur->left;
        return cur;
    }
    
    TreeNode* f(TreeNode* root, int key)
    {
        if(root == NULL)
            return root;
        
        if(root->val == key) {
            // If leaf node (no children)
            if(root->left == NULL and root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left == NULL)     // only right child
            {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if(root->right == NULL)    // only left child
            {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {                          // two children (degree 2)
                TreeNode* inorderSuccessor = getInorderSuccessor(root);
                root->val = inorderSuccessor->val;
                root->right = f(root->right,inorderSuccessor->val);
                return root;
            }
        }
        else if(key < root->val) {
            root->left = f(root->left,key);
        }
        else {
            root->right = f(root->right,key);
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return f(root,key);
    }
};