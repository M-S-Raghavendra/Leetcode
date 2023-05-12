class Solution {
private:
    long long f(int i, vector<vector<int>> &q, vector<long long> &dp)
    {
        if(i >= q.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        long long notpick = 0 + f(i+1,q,dp);
        long long pick = q[i][0] + f(i+q[i][1]+1,q,dp);
        
        return dp[i] = max(notpick,pick);
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans;
        vector<long long> dp(questions.size(),-1);
        
        ans = f(0,questions,dp);
        
        return ans;
    }
};