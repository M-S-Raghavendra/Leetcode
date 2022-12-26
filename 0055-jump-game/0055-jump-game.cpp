class Solution {
public:
    bool canJump(vector<int>& nums) {
        //DP
        // vector<int> dp(nums.size(),-1);
        // return f(0,nums,dp);
        
        //Greedy
        int n = nums.size();
        int reach = 0, i;
        for(i=0;i<n and i<=reach;i++)
            reach = max(reach, i+nums[i]);
        return (i==n);
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

// bool canJump(int A[], int n) {
//     int i = 0;
//     for (int reach = 0; i < n && i <= reach; ++i)
//         reach = max(i + A[i], reach);
//     return i == n;
// }