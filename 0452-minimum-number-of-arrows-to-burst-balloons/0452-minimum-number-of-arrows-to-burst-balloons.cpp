class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans = 1;
        int n = points.size();
        int end = points[0][1];
        
        if(n == 1)
            return 1;
        
        for(int i=1;i<n;i++)
        {
            if(points[i][0] > end)
            {
                end = points[i][1];
                ans += 1;
            }
        }
        
        return ans;
    }
};