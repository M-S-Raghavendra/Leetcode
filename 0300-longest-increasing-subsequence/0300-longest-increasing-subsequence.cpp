class Solution {
public:
    int f(int i, int prevIndex, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i >= nums.size())
            return 0;
        
        if(dp[i][prevIndex+1] != -1)
            return dp[i][prevIndex+1];
        
        int pick = 0, notpick = 0;
        if(prevIndex == -1 or nums[i] > nums[prevIndex])
            pick = 1 + f(i+1,i,nums,dp);
        notpick = 0 + f(i+1,prevIndex,nums,dp);
        
        return dp[i][prevIndex+1] = max(notpick,pick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};