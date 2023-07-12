class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // return f(0,n,dp);
        
        dp[n] = 1;
        for(int i=n-1;i>=0;i--)
        {
            dp[i] = dp[i+1];
            if(i < n-1)
            dp[i] += dp[i+2];
        }
        
        return dp[0];
    }
    
    int f(int i, int n, vector<int> &dp)
    {
        if(i == n)
            return 1;
        if(i > n)
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = f(i+1,n,dp) + f(i+2,n,dp);
    }
};