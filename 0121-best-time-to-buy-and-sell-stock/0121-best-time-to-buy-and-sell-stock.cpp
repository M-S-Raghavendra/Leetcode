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
        
//         int n=prices.size();
//         int pmn=prices[0];
//         int ans=0;
//         if(n==1) return 0;
//         for(int i=1;i<n;i++)
//         {
//             if(prices[i]<pmn)
//                 pmn=prices[i];
//             else
//                 ans=max(ans,prices[i]-pmn);
//         }
//         return ans;
    }
};