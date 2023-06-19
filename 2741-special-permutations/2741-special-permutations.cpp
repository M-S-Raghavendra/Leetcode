class Solution {
public:
    int mod = 1e9 + 7;
    
    int f(int prevIndex, int mask, int setbits, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(setbits == nums.size())
        {
            return 1;
        }
        
        if(dp[prevIndex+1][mask] != -1) return dp[prevIndex+1][mask];
        
        int cntPermutations = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(mask & (1<<i))
                continue;
            if(prevIndex == -1 || (nums[prevIndex]%nums[i] == 0) || (nums[i]%nums[prevIndex] == 0))
                cntPermutations = (cntPermutations + f(i, mask | (1<<i), setbits+1,nums,dp)) % mod;
        }
        
        return dp[prevIndex+1][mask] = cntPermutations;
    }
    
    int specialPerm(vector<int>& nums) {
        int prevIndex = -1;
        int setbits = 0;
        int mask = 0;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>((1<<14),-1));
        // setbits is not a separate state, because it is/can be derived from mask
        return f(prevIndex,mask,setbits,nums,dp);
    }
};