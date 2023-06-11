class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), par(n);
        vector<int> ans;
        int maxi = 0, lastIndex = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            par[i] = i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i] % nums[prev] == 0 and dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    par[i] = prev;                    
                }
            }
            if(maxi < dp[i])
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        int cur = lastIndex;
        while(par[cur] != cur)
        {
            ans.push_back(nums[cur]);
            cur = par[cur];
        }
        ans.push_back(nums[cur]);
        
        return ans;
    }
};