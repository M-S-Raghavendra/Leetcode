class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int presum = 0;
        m[0]++;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            presum += nums[i] & 1;
            if(m.find(presum - k) != m.end())
                ans += m[presum - k];
            m[presum]++;
        }
        
        return ans;
    }
};