class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(101,-1));
        
        return f(0,0,s,dp);
    }
    
    bool f(int i, int open, string &s, vector<vector<int>> &dp)
    {
        if(i == s.size())
            return open == 0;
        if(open < 0) return false;
        
        if(dp[i][open] != -1) return dp[i][open];
        
        if(s[i] == '*')
        {
            bool nothing = f(i+1,open,s,dp);
            bool op = f(i+1,open+1,s,dp);
            bool close = f(i+1,open-1,s,dp);
            return dp[i][open] = nothing or op or close;
        }
        else if(s[i] == '(')
            return dp[i][open] = f(i+1,open+1,s,dp);
        else
            return dp[i][open] = f(i+1,open-1,s,dp);
    }
};