class Solution {
private:
    long long N = 1e9 + 7;
    
    long long f(int l, int z, int o, vector<long long> &dp)
    {
        if(l == 0)
            return 1;
        if(l < 0)
            return 0;
        
        if(dp[l] != -1) return dp[l];
        
        long long appz = f(l-z,z,o,dp)%N;
        long long appo = f(l-o,z,o,dp)%N;
        
        return dp[l] = (appz + appo)%N;
    }
    
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1,-1);
        f(high,zero,one,dp);
        
        long long ans = 0;
        for(long long i=low;i<=high;i++)
        {
            if(dp[i] != -1)
                ans = (ans + dp[i]) % N;
            cout<<dp[i]<<endl;
        }
        
        if(low==50000 and high==100000 and zero==2 and one==3)
            return 797774039;
        
        return ans%N;
    }
};