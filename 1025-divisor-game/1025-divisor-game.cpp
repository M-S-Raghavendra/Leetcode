class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1,false);
        
        dp[1] = false;
        
        for(int i=1;i<=n;i++)
        {
            bool ans = false;
            for(int x=i-1;x>=1;x--)
            {
                if(i%x == 0)
                    ans |= !dp[i-x];
                if(ans) break;
            }
            dp[i] = ans;
        }
        
        return dp[n];
        // return f(n,dp);
    }

    bool f(int n, vector<int>& dp)
    {
        if(n == 1)
            return false;

        if(dp[n] != -1) return dp[n];
        
        bool ans = false;
        for(int x=n-1;x>=1;x--)
        {
            if(n%x == 0)
                ans |= !f(n-x,dp);
            if(ans) break;
        }

        return dp[n] = ans;
    }
};