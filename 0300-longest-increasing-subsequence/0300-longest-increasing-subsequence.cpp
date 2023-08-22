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
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,dp);
        
        // O(nlogn) Time, O(n) space, Binary search
        vector<int> sub;
        for(int i=0;i<n;i++)
        {
            if(sub.empty() or sub.back() < nums[i])
                sub.push_back(nums[i]);
            else {
                int ind = lower_bound(sub.begin(),sub.end(),nums[i]) - sub.begin();
                sub[ind] = nums[i];
            }
        }
        
        return sub.size();
        
        // O(n^2) Time, O(n) space
//         vector<int> dp(n,1);
//         int ans = 1;
        
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(nums[i] > nums[j])
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 ans = max(ans,dp[i]);
//             }
//         }
        
//         return ans;
    }
};