class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // vector<vector<int>> dp(m,vector<int>(n,0));
        int maxi = 0;
        vector<int> prev(n,0), cur(n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 or j == 0 or matrix[i][j] == '0')
                    cur[j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                    cur[j] = 1 + min(prev[j-1],min(prev[j],cur[j-1]));
                // cout<<dp[i][j]<<" ";
                maxi = max(maxi,cur[j]);
            }
            prev = cur;
            // cout<<endl;
        }
        return maxi*maxi;
    }
};