class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++)
        {
            ans.push_back(f(i));
        }
        
        return ans;
    }
    
    int f(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += (n&1);
            n >>= 1;
        }
        
        return ans;
    }
};