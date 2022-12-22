class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return f(n-1,amount,coins,n,dp);
        
        for(int val=0;val<=amount;val++)
        {
            if(val%coins[0] == 0) dp[0][val] = 1;
            else dp[0][val] = 0;
        }
        
        for(int ind = 1;ind<n;ind++)    
        {
            for(int val=0;val<=amount;val++)
            {
                int nottake = dp[ind-1][val];
                int take = 0;
                if(coins[ind] <= val)
                    take = dp[ind][val-coins[ind]];
                dp[ind][val] = (take + nottake);
            }
        }
        
        return dp[n-1][amount];
    }
    
    int f(int ind, int val, vector<int> &deno, int n, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(val%deno[ind] == 0) return 1;
            else return 0;
        }
        
        if(dp[ind][val] != -1) return dp[ind][val];
        
        int nottake = f(ind-1,val,deno,n,dp);
        int take = 0;
        if(deno[ind] <= val)
            take = f(ind,val-deno[ind],deno,n,dp);
        return dp[ind][val] = (take + nottake);
    }
};