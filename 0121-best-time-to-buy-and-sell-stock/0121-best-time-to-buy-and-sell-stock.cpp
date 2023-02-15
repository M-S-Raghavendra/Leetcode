class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit = 0, cur;
        int mini = prices[0];
        
        for(int i=1;i<n;i++)
        {
            cur = prices[i] - mini;
            profit = max(profit,cur);
            mini = min(mini,prices[i]);
        }
        
        return profit;
    }
};