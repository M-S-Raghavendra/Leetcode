class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        dp[n-1] = 0;
        
        for(int ind=n-2;ind>=0;ind--)
        {
            int temp = 1e9;
            for(int i=1;i<=nums[ind];i++)
            {
                if(ind+i < n)
                    temp = min(temp, 1 + dp[ind+i]);
            }

            dp[ind] = temp;
        }
                           
        return dp[0];
                           
        // return f(0,nums,dp);
    }
    
    int f(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind >= nums.size()-1)
            return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int temp = 1e9;
        for(int i=1;i<=nums[ind];i++)
        {
            temp = min(temp, 1 + f(ind+i,nums,dp));
        }
        
        return dp[ind] = temp;
    }
};