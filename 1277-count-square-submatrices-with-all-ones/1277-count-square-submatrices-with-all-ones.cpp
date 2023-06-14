class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Take every cell as bottom-right corner of a square
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sqRB(m,vector<int>(n,0));
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 or j == 0)
                    sqRB[i][j] = matrix[i][j];
                else if(matrix[i][j] == 0)
                    sqRB[i][j] = 0;
                else
                    sqRB[i][j] = 1 + min(sqRB[i-1][j], min(sqRB[i-1][j-1],sqRB[i][j-1]));
                
                ans += sqRB[i][j];
            }
        }
        
        return ans;
    }
};