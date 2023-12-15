class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> onerow(m), onecol(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    onerow[i]++;
                    onecol[j]++;
                }
            }
        }
        
        vector<vector<int>> diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                diff[i][j] = onerow[i] + onecol[j] - (n-onerow[i]) - (m-onecol[j]);
            }
        }
        
        return diff;
    }
};