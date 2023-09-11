class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int cur = 0;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            cur += nums[i];
            ans.push_back(nums[i]);
            if(cur > sum-cur)
                break;
        }
        
        return ans;
    }
};