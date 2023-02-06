class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = n;
        int i = 0;
        vector<int> ans;
        
        while(m < (2*n))
        {
            ans.push_back(nums[i++]);
            ans.push_back(nums[m++]);
        }
        return ans;
    }
};