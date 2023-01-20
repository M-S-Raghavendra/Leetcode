class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int> r(n), c(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                r[i] = max(r[i],grid[i][j]);
                c[j] = max(c[j],grid[i][j]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans += min(r[i],c[j]) - grid[i][j];
            }
        }
        return ans;
    }
};