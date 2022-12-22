class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
    
    int countPartitions(int n, int d, vector<int> &arr) 
    {
        int totSum = 0;
        for(auto x:arr)
            totSum += x;
        if((totSum-d) < 0 or (totSum-d)%2 == 1) return 0;
        int k = (totSum-d)/2;

        vector<vector<int>> dp(n,vector<int>(k+1,0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0] != 0 and arr[0] <= k) dp[0][arr[0]] = 1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int nottake = dp[i-1][j];
                int take = (j-arr[i] >= 0)?dp[i-1][j-arr[i]]:0;
                dp[i][j] = (take + nottake);
            }
        }

        return (dp[n-1][k]);
    }
};