class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = nums[0];
        int ans = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            sum += nums[i];
            int mx = ceil(1.0*sum/(i+1));
            
            ans = max(ans,mx);
        }
        
        return ans;
    }
};