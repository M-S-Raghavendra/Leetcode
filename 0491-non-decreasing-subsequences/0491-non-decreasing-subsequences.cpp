class Solution {    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v;
        
        f(0,nums,v,s);
        vector<vector<int>> ans;
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
    
    void f(int ind, vector<int> &nums, vector<int> &v, set<vector<int>> &s)
    {
        if(ind >= nums.size())
        {
            if(v.size() > 1)
                s.insert(v);
            return ;
        }
        
        f(ind+1,nums,v,s);
        
        if(v.empty() or nums[ind] >= v.back())
        {
            v.push_back(nums[ind]);
            f(ind+1,nums,v,s);
            v.pop_back();
        }
    }
};