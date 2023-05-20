class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix_sum=0, count=0;
        unordered_map<int,int> m;
        m[0]++;
        
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum += nums[i];
            int req = prefix_sum - k;
            
            if(m.find(req) != m.end())
                count += m[req];
            m[prefix_sum]++;
        }
        return count;
    }
};