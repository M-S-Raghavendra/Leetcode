class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
    
    bool f(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind == nums.size()-1)
            return true;
        
        if(dp[ind] != -1) return dp[ind];
        
        for(int i=ind+1;i<=ind+nums[ind] and i<nums.size();i++)
        {
            if(f(i,nums,dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
};