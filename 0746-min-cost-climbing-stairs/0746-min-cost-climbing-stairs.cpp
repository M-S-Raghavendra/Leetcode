class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        
        // f(0,cost,dp);
        // return min(dp[0],dp[1]);
        
        dp[n] = 0;
        for(int i=n-1;i>=0;i--)
        {
            int one, two = 1e9;
            one = cost[i] + f(i+1,cost,dp);
            if(i < n-1)
            two = cost[i] + f(i+2,cost,dp);

            dp[i] = min(one,two);
        }
        
        return min(dp[0],dp[1]);
    }
    
    int f(int i, vector<int> &cost, vector<int> &dp)
    {
        if(i >= cost.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int one = cost[i] + f(i+1,cost,dp);
        int two = cost[i] + f(i+2,cost,dp);
        
        return dp[i] = min(one,two);
    }
};