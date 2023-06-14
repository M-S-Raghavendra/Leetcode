struct Node {
    Node* links[2] = {NULL};
    
    bool containsKey(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* newnode) {
        links[bit] = newnode;
    }
    
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insertBinary(int num) {
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
    
    int maxiXOR(int num) {
        Node* node = root;
        int ans = 0;
        
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(node == NULL)
                return -1;
            if(node->containsKey(!bit)) {
                node = node->get(!bit);
                ans = ans | (1<<i);
            }
            else {      // either 0 or 1 should be there, till length becomes 32
                node = node->get(bit);
            }
        }
        
        return ans;
    }
};

class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans(queries.size());
        Trie trie;
        
        int i = 0;
        for(auto &x:queries)
        {
            x.push_back(i++);
        }
        
        sort(queries.begin(),queries.end(),comp);
        sort(nums.begin(),nums.end());
        
        int j = 0;
        for(int i=0;i<queries.size();i++)
        {
            while(j < n and nums[j] <= queries[i][1])
            {
                trie.insertBinary(nums[j]);
                j++;
            }
            
            ans[queries[i][2]] = trie.maxiXOR(queries[i][0]);
        }
        
        return ans;
    }
};