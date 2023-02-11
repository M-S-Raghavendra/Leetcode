class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
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