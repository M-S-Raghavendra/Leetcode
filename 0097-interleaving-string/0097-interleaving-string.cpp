class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        
        if(s1.empty()) return (s2 == s3);
        if(s2.empty()) return (s1 == s3);
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return f(n-1,m-1,k-1,s1,s2,s3,dp);
    }
    
    bool f(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp)
    {
        if(i < 0 and j < 0 and k < 0)
            return true;
        if(i<0 and j<0 and k>=0)
            return false;
        
        if(i>=0 and j>=0 and k>=0 and dp[i+1][j+1][k+1] != -1) return dp[i+1][j+1][k+1];
        
        bool a = false, b = false;
        if(i >= 0 and k >= 0 and s1[i] == s3[k])
             a = f(i-1,j,k-1,s1,s2,s3,dp);
        
        if(j >= 0 and k >= 0 and s2[j] == s3[k])
            b = f(i,j-1,k-1,s1,s2,s3,dp);
        return dp[i+1][j+1][k+1] = (a or b);
    }
};