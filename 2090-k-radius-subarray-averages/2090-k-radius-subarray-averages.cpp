class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int len = 2*k + 1;
        int i = len;
        long long sum = 0;
        
        if(k > len or len > n)
            return ans;
        
        for(int j=0;j<len;j++)
            sum += nums[j];
        
        while(i <= n)
        {
            ans[i - k - 1] = sum/len;
            sum -= nums[i - len];
            if(i < n)
                sum += nums[i];
            i++;
        }
        
        return ans;
    }
};