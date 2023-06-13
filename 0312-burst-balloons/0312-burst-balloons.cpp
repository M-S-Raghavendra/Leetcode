class Solution {
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int ind=i;ind<=j;ind++)
        {
            int coins = (nums[i-1]*nums[j+1]*nums[ind]) + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);
            maxi = max(maxi,coins);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        // Partition DP
        // Main logic is "instead of choosing 1st balloon to be bursted,
        // choose last ballon to be bursted, i.e, reverse approach -> last ballon bursted to
        // 1st balloon bursted"
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums,dp);
    }
};