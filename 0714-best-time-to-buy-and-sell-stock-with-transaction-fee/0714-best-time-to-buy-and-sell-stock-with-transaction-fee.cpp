class Solution {
public:
    int f(int i, int buy, vector<int> &p, vector<vector<int>> &dp, int fee)
    {
        if(i >= p.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy)
            return dp[i][buy] = max(-p[i] + f(i+1,0,p,dp,fee), 0 + f(i+1,1,p,dp,fee));
        else
            return dp[i][buy] = max(p[i] + f(i+1,1,p,dp,fee) - fee, 0 + f(i+1,0,p,dp,fee));
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
    }
};