class Solution {
public:
    int coinChange(vector<int>& num, int x) {
        int n = num.size();
    //     vector<vector<long long>> dp(n,vector<long long>(x+1,0));
    //     long long ans = f(n-1,x,num,n,dp);
    //     return (ans >= 1e10)?-1:ans;

        vector<long long> prev(x+1,0), cur(x+1,0);

        for(int i=0;i<=x;i++)
        {
            if(i%num[0] == 0) 
                prev[i] = i/num[0];
            else prev[i] = 1e10;
        }

        for(int ind=1;ind<n;ind++)
        {
            for(int X=0;X<=x;X++)
            {
                long long nottake = 0 + prev[X];
                long long take = 1e10;
                if(num[ind] <= X)
                    take = 1 + cur[X-num[ind]];
                cur[X] = min(nottake,take);
            }
            prev = cur;
        }

        long long ans = prev[x];
        if(ans >= 1e10)
            return -1;
        return prev[x];
    }
    
    long long f(int ind, int x, vector<int> &num, int n, vector<vector<long long>> &dp)
    {
        if(ind == 0)
        {
            if(x%num[0] == 0) return x/num[0];
            else return 1e10;
        }
        if(dp[ind][x] != -1) return dp[ind][x];

        long long nottake = 0 + f(ind-1,x,num,n,dp);
        long long take = 1e10;
        if(num[ind] <= x)
            take = 1 + f(ind,x-num[ind],num,n,dp);
        return dp[ind][x] = min(nottake,take);
    }

};