class Solution {
public:
    vector<vector<int>> dp;
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n,vector<int>(target+1,-1));
        int ans=  f(0,nums,target);
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
    
    int f(int i, vector<int> &nums, int tar)
    {
        if(tar == 0)
            return 1;
        if(i == nums.size())
            return 0;
        
        if(dp[i][tar] != -1) return dp[i][tar];
        
        int np = f(i+1,nums,tar);
        int p = 0;
        if(nums[i] <= tar)
        {
            p = f(0,nums,tar-nums[i]);
        }
                
        return dp[i][tar] = np + p;
    }
};