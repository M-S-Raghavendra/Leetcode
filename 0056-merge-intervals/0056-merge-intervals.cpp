class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort by start time
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        int n = intervals.size();
        
        for(int i=0;i<n;i++)
        {
            if(ans.empty() or ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans;
    }
};