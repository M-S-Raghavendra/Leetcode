class Solution {
public:
    int f(int i, int buy, vector<int> &p, vector<vector<int>> &dp)
    {
        if(i >= p.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy)
            return dp[i][buy] = max(-p[i] + f(i+1,0,p,dp), 0 + f(i+1,1,p,dp));
        else
            return dp[i][buy] = max(p[i] + f(i+2,1,p,dp), 0 + f(i+1,0,p,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};