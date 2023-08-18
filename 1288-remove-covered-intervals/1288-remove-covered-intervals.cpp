class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        int prev = 0;
        int cnt = 0;
        
        for(int i=1;i<n;i++)
        {
            if(intervals[prev][1] >= intervals[i][1])
                cnt++;
            else
                prev = i;
        }
        
        return n - cnt;
    }
};