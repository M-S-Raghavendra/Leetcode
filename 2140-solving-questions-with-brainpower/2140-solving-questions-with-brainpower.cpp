class Solution {
public:
    vector<long long> dp;
    
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(),-1);
        return f(0,questions);
    }
    
    long long f(int i, vector<vector<int>> &q)
    {
        if(i >= q.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        long long np = 0 + f(i+1,q);
        long long p = q[i][0] + f(i+q[i][1]+1, q);
        
        return dp[i] = max(np,p);
    }
};