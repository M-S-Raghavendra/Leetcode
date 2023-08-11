class Solution {
public:
    vector<vector<long long>> dp;
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<long long>(2,-1));
        return f(0,0,nums);
    }
    
    long long f(int i, int isOdd, vector<int> &nums)
    {
        if(i == nums.size())
            return 0;
        
        if(dp[i][isOdd] != -1) return dp[i][isOdd];
        
        if(!isOdd) {
            return dp[i][isOdd] = max(nums[i] + f(i+1,1,nums), 0 + f(i+1,0,nums));
        }
        else {
            return dp[i][isOdd] = max(-nums[i] + f(i+1,0,nums), 0 + f(i+1,1,nums));
        }
    }
};