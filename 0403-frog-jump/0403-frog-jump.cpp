class Solution {
public:
    unordered_map<long long,long long> m;
    vector<vector<long long>> dp;
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        long long n = stones.size();
        
        for(long long i=0;i<n;i++)
            m[stones[i]]= i;
        
        dp.resize(n,vector<long long>(2001,-1));
        return f(1,1,stones);
    }
    
    bool f(long long i, long long ps, vector<int> &s)
    {
        if(i == s.size()-1)
            return true;
        
        if(dp[i][ps] != -1) return dp[i][ps];
        
        if((long long)s[i]+ps-1 <= INT_MAX and m.count(s[i]+ps-1) and m[s[i]+ps-1] > i)
        {
            if(f(m[s[i]+ps-1],ps-1,s)) return dp[i][ps] = true;
        }
        if((long long)s[i]+ps <= INT_MAX and m.count(s[i]+ps) and m[s[i]+ps] > i) 
        {
            if(f(m[s[i]+ps],ps,s)) return dp[i][ps] = true;
        }
        if((long long)s[i]+ps+1 <= INT_MAX and m.count(s[i]+ps+1) and m[s[i]+ps+1] > i)
        {
            return dp[i][ps] = f(m[s[i]+ps+1],ps+1,s);
        }
        
        return dp[i][ps] = false;
    }
};