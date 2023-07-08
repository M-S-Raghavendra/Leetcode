class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j;
        int cnt = k;
        
        for(j=0;j<n;j++)
        {
            if(nums[j] == 0)
                cnt--;
            if(cnt < 0 and nums[i++] == 0)
                cnt++;
        }
        
        return j-i;
    }
};