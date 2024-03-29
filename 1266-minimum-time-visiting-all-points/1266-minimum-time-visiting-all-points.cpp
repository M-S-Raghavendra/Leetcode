class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        
        for(int i=1;i<n;i++)
        {
            int x = abs(points[i][0]-points[i-1][0]);
            int y = abs(points[i][1]-points[i-1][1]);
            int mn = min(x, y);
            ans += mn;
            ans += abs(x-y);
        }
        
        return ans;
    }
};