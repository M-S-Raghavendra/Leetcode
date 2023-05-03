class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m1,m2;
        for(auto x:nums1)
            m1.insert(x);
        for(auto x:nums2)
            m2.insert(x);
        
        vector<vector<int>> ans;
        vector<int> diff;
        
        for(auto x:m1)
        {
            if(m2.find(x) == m2.end())
                diff.push_back(x);
        }
        ans.push_back(diff);
        diff.clear();
        
        for(auto x:m2)
        {
            if(m1.find(x) == m1.end())
                diff.push_back(x);
        }
        ans.push_back(diff);
        
        return ans;
    }
};