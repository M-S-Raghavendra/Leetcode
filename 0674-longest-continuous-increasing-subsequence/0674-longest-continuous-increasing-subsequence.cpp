class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        int ans = 1;
        
        while(i < n and j < n)
        {
            while(j < n and nums[j] > nums[j-1])
                j++;
            ans = max(ans, j-i);
            i = j;
            j++;
        }
        
        return ans;
    }
};