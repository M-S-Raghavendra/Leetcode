class Solution {
public:
    int x[8] = {-1,-1,-2,-2,1,1,2,2};
    int y[8] = {-2,2,-1,1,-2,2,-1,1};
    
    double knightProbability(int n, int k, int row, int column) {
        double ans = 0;
        queue<pair<int,int>> q;
        q.push({row,column});
        
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        
        double cnt = dfs(row,column,n,k,dp);
        return cnt / (double)pow(8,k);
    }
    
    double dfs(int i, int j, int n, int k, vector<vector<vector<double>>> &dp)
    {
        if(i < 0 or j < 0 or i >= n or j >= n)
            return 0;
        if(k == 0)
            return 1;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        double ans = 0;
        for(int kk=0;kk<8;kk++)
        {
            int ni = i + x[kk];
            int nj = j + y[kk];
            
            ans += dfs(ni,nj,n,k-1,dp);
        }
        
        return dp[i][j][k] = ans;
    }
};