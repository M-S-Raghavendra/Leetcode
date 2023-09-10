class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        vector<long long> dp(n+1,0);
        dp[1] = 1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i] = (i%mod * (dp[i-1]%mod * ((i-1)*2 + 1))%mod) % mod;
        }
        
        return dp[n];
    }
};