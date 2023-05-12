class Solution {
private:
    long long f(int i, vector<vector<int>> &q, vector<long long> &dp)
    {
        if(i >= q.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        long long notpick = 0 + f(i+1,q,dp);
        long long pick = q[i][0] + f(i+q[i][1]+1,q,dp);
        
        return dp[i] = max(notpick,pick);
    }
    
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long ans;
        int n = q.size();
        vector<long long> dp(n,-1);
        
        // ans = f(0,q,dp);
        
        dp[n-1] = q[n-1][0];
        
        for(int i=n-2;i>=0;i--)
        {
            long long notpick = 0, pick = q[i][0];
            notpick = 0 + dp[i+1];
            if(i+q[i][1]+1 < n)
                pick += dp[i+q[i][1]+1];

            dp[i] = max(notpick,pick);
        }
        
        return dp[0];
    }
};