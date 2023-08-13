class Solution {
public:
    vector<int> dp;
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return f(0,nums);
    }
    
    bool f(int i, vector<int> &nums)
    {
        if(i == nums.size()) return true;
        
        if(dp[i] != -1) return dp[i];
        
        int n = nums.size();
        bool ans = false;
        
        if(i+1 < n and nums[i] == nums[i+1])
            ans |= f(i+2,nums);
        if(i+1<n and i+2<n and nums[i] == nums[i+1] and nums[i+1] == nums[i+2])
            ans |= f(i+3,nums);
        if(i+1<n and i+2<n and nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1)
            ans |= f(i+3,nums);
        
        return dp[i] = ans;
    }
};