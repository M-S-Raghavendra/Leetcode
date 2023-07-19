class Solution {
private:
    // never use equal to (=) in comparator
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        
        int ans = 0;
        int prev = 0;
        int n = intervals.size();
                               
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] < intervals[prev][1])
                ans++;
            else
                prev = i;
        }
        return ans;
    }
};