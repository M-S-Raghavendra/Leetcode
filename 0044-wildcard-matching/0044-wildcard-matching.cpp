class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[0][0] = true;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = dp[i-1][0] and (p[i-1] == '*');
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[i-1] == s[j-1] or p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
        // return f(n-1,m-1,p,s,dp);
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
        
        if(p[i] == s[j] or p[i] == '?')
            return dp[i][j] = f(i-1,j-1,p,s,dp);
        else if(p[i] == '*')
        {
            return dp[i][j] = f(i-1,j,p,s,dp) or f(i,j-1,p,s,dp);
        }
        else return dp[i][j] = false;
    }
};