class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int i=0, j=n-1;
        
        vector<int> power(n,1);
        for(int i=1;i<n;i++)
            power[i] = (power[i-1] * 2)%mod;
        
        while(i <= j)
        {
            if(nums[i] + nums[j] <= target)
            {
                ans = (ans + power[j-i]%mod)%mod;
                i++;
            }
            else
                j--;
        }
        
        return ans;
    }
};