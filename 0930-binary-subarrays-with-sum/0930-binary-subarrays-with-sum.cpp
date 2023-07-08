class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> m;
        int presum = 0;
        m[0]++;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            presum += nums[i];
            if(m.find(presum - goal) != m.end())
                ans += m[presum - goal];
            m[presum]++;
        }
        
        return ans;
    }
};