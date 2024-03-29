class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer(n);
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        // for(int col = 0; col < n; col++)
        // {
        //     answer[col] = f(0,col,grid,dp);
        // }
        
        for(int i=m;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i == m) dp[i][j] = j;
                else {
                    if(grid[i][j] == 1)
                    {
                        if(j+1 < grid[0].size() and grid[i][j+1] == 1)
                            dp[i][j] = dp[i+1][j+1];
                        else
                            dp[i][j] = -1;
                    }
                    else {
                        if(j-1 >= 0 and grid[i][j-1] == -1)
                            dp[i][j] = dp[i+1][j-1];
                        else
                            dp[i][j] = -1;
                    }
                }
            }
        }
        vector<int> ans = dp[0];
        ans.pop_back();
        return ans;
        // return answer;
    }
    
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(i == grid.size())
            return j;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(grid[i][j] == 1)
        {
            if(j+1 < grid[0].size() and grid[i][j+1] == 1)
                return dp[i][j] = f(i+1,j+1,grid,dp);
            else
                return dp[i][j] = -1;
        }
        else {
            if(j-1 >= 0 and grid[i][j-1] == -1)
                return dp[i][j] = f(i+1,j-1,grid,dp);
            else
                return dp[i][j] = -1;
        }
    }
};