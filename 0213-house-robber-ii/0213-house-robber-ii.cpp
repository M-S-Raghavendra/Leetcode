class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        bool last = false;
        
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(n-1,last,nums,dp);
    }
    
    int f(int i, bool &last, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i < 0)
            return 0;
        if(i == 0 and !last)
            return nums[i];
        
        if(dp[i][last] != -1) return dp[i][last];
        
        int rob = INT_MIN, notrob;
        if(i == nums.size()-1) last = true;
        if(i != 0 or !last)
            rob = nums[i] + f(i-2,last,nums,dp);
        if(i == nums.size()-1) last = false;
        notrob = 0 + f(i-1,last,nums,dp);
        
        return dp[i][last] = max(rob,notrob);
    }
};