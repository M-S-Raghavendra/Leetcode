class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> s;
        int i = 0;
        long long ans = 0;
        
        for(int j=0;j<nums.size();j++)
        {
            s.insert(nums[j]);
            while(*s.rbegin() - *s.begin() > 2)
            {
                s.erase(s.find(nums[i++]));
            }
            // number of subarrays ending at index j
            ans += j-i+1;
        }
        
        return ans;
    }
};