class Solution {
private:
    int d[5] = {0,1,0,-1,0};
    int m,n;
    vector<vector<int>> dp;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m,vector<int>(n,-1));
        
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                f(i,j,matrix);
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
    
    int f(int i, int j, vector<vector<int>> &mat)
    {
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1;
        int temp = mat[i][j];
        mat[i][j] = -1;
        
        for(int k=0;k<4;k++)
        {
            int ni = i + d[k];
            int nj = j + d[k+1];
            
            if(ni>=0 and nj>=0 and ni<m and nj<n and mat[ni][nj] != -1 and mat[ni][nj] > temp)
            {
                ans = max(ans, 1+f(ni,nj,mat));
            }
        }
        
        mat[i][j] = temp;
        return dp[i][j] = ans;
    }
};