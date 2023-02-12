class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return f(n-1,m-1,p,s,dp);
    }
    
    bool f(int i, int j, string &p, string &s, vector<vector<int>> &dp)
    {
        if(j < 0)
        {
            for(int k=i;k>=0;k--)
                if(p[k] != '*')
                    return false;
            return true;
        }
        if(i < 0) return false;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[i] == '?')
            return dp[i][j] = f(i-1,j-1,p,s,dp);
        else if(p[i] == '*')
        {
            bool temp = false;
            for(int ind=0;ind<=j+1;ind++)
            {
                temp |= f(i-1,j-ind,p,s,dp);
            }
            return dp[i][j] = temp;
        }
        else {
            if(p[i] == s[j])
                return dp[i][j] = f(i-1,j-1,p,s,dp);
            else return dp[i][j] = false;
        }
    }
};