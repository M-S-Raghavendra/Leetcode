class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(20,-1);
        return f(n,dp);
    }
    
    int f(int n, vector<int> &dp)
    {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int ans = 0;
        
        if(dp[n] != -1) return dp[n];
        
        for(int i=1;i<=n;i++)
        {
            ans += f(i-1,dp) * f(n-i,dp);
        }
        
        return dp[n] = ans;
    }
};