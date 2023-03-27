class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i == m-1 and j == n-1)
                    dp[m-1][n-1] = grid[m-1][n-1];
                else
                {
                    int s = INT_MAX;
                    if(j+1 < n)
                        s = min(s,dp[i][j+1]);
                    if(i+1 < m)
                        s = min(s,dp[i+1][j]);
                    dp[i][j] = grid[i][j] + s;
                }
            }
        }
        
        return dp[0][0];
    }
};