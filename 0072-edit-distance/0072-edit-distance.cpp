class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=m;i++)
            dp[0][i] = i;
        for(int i=1;i<=n;i++)
            dp[i][0] = i;
                
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {        
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 0 + dp[i-1][j-1];
                else {
                    int insert = 1 + dp[i][j-1];
                    int dele = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insert,min(dele,replace));
                }
            }
        }
        return dp[n][m];
        // return f(n-1,m-1,word1,word2,dp);
    }
    
    int f(int i, int j, string &w1, string &w2, vector<vector<int>> &dp)
    {
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(w1[i] == w2[j])
            return dp[i][j] = 0 + f(i-1,j-1,w1,w2,dp);
        int insert = 1 + f(i,j-1,w1,w2,dp);
        int dele = 1 + f(i-1,j,w1,w2,dp);
        int replace = 1 + f(i-1,j-1,w1,w2,dp);
        
        return dp[i][j] = min(insert,min(dele,replace));
    }
};