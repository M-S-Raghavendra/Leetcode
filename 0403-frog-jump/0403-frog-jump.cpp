class Solution {
public:
    unordered_set<int> set;
    vector<vector<int>> dp;
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        for(auto x:stones)
            set.insert(x);
        
        int n = stones.size();
        
        dp.resize(n,vector<int>(2001,-1));
        return f(1,1,stones);
    }
    
    bool f(int i, int ps, vector<int> &s)
    {
        if(i == s.size()-1)
            return true;
        
        if(dp[i][ps] != -1) return dp[i][ps];
        
        if(s[i]+ps-1 > s[i] and set.count(s[i]+ps-1))
        {
            int ind = lower_bound(s.begin()+i+1,s.end(),s[i]+ps-1) - s.begin();
            if(f(ind,ps-1,s)) return dp[i][ps] = true;
        }
        if(s[i]+ps > s[i] and set.count(s[i]+ps)) {
            int ind = lower_bound(s.begin()+i+1,s.end(),s[i]+ps) - s.begin();
            if(f(ind,ps,s)) return dp[i][ps] = true;
        }
        if(s[i]+ps+1 > s[i] and set.count(s[i]+ps+1)) {
            int ind = lower_bound(s.begin()+i+1,s.end(),s[i]+ps+1) - s.begin();
            return dp[i][ps] = f(ind,ps+1,s);
        }
        
        return dp[i][ps] = false;
    }
};