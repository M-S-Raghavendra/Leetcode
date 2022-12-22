class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return f(n-1,amount,coins,n,dp);
        
        vector<int> prev(amount+1,-1), cur(amount+1,-1);
        
        for(int val=0;val<=amount;val++)
        {
            if(val%coins[0] == 0) prev[val] = 1;
            else prev[val] = 0;
        }
        
        for(int ind = 1;ind<n;ind++)    
        {
            for(int val=0;val<=amount;val++)
            {
                int nottake = prev[val];
                int take = 0;
                if(coins[ind] <= val)
                    take = cur[val-coins[ind]];
                cur[val] = (take + nottake);
            }
            prev = cur;
        }
        
        return prev[amount];
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