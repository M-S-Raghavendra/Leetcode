class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        double ans = INT_MIN;
        double cur = 0;
        
        for(int i=0;i<k;i++)
            cur += nums[i];
        double div = cur/k;
        ans = max(ans,div);
        
        for(int i=k;i<n;i++)
        {
            cur -= nums[i-k];
            cur += nums[i];
            div = cur/k;
            ans = max(ans,div);
        }
        return ans;
    }
};