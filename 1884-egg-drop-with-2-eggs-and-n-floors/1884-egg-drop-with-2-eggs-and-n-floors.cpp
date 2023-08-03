class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return f(n,2,dp);
    }
    
    int f(int n, int k, vector<vector<int>> &dp)
    {
        if(n == 0 or n == 1) return n;
        if(k == 1) return n;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int s = 1, e = n;
        int br, notbr;
        int ans = INT_MAX;
        
        while(s <= e)
        {
            int m = (s + e)/2;
            
            br = 1 + f(m-1,k-1,dp);
            notbr = 1 + f(n-m,k,dp);
            
            ans = min(ans, max(br, notbr));
            
            if(br > notbr)
                e = m-1;
            else
                s = m+1;
        }
        
        return dp[n][k] = ans;
    }
};