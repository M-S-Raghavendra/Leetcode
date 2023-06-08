class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0, j = n-1;
        int cnt= 0, ans = 0;
        
        while(i<m)
        {
            while(j>=0 and grid[i][j] < 0)
            {
                cnt++;
                j--;
            }
            ans += cnt;
            i++;
        }
        return ans;
    }
};