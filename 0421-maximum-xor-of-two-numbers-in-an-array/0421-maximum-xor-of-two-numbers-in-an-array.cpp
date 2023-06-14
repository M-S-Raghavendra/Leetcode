class Node {
    Node* links[2] = {NULL};
    
public:
    bool containsKey(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* newnode) {
        links[bit] = newnode;
    }
    
    Node* get(int bit) {
        return links[bit];
    }
    
    void insertBinary(int num, Node* root)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int maxiXOR(int num, Node* root) {
        Node* node = root;
        int ans = 0;
        
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(node->containsKey(!bit)) {
                node = node->get(!bit);
                ans = ans | (1<<i);
            }
            else {
                node = node->get(bit);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        Node* node = root;
        for(auto x:nums)
        {
            node->insertBinary(x,root);
        }
        
        int ans = 0;
        for(auto x:nums)
        {
            ans = max(ans, node->maxiXOR(x,root));
        }
        
        return ans;
    }
};