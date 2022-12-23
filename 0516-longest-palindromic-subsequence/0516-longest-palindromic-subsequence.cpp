class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];        
        // return f(n-1,n-1,s,t);
    }
    
    int f(int i, int j, string &s, string &t)
    {
        if(i < 0 or j < 0)
            return 0;
        
        if(s[i] == t[j])
            return 1 + f(i-1,j-1,s,t);
        else
            return max(f(i-1,j,s,t), f(i,j-1,s,t));
    }
};