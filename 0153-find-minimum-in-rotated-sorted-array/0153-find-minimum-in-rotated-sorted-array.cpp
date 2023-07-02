class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        int ans = INT_MAX;
        
        while(s < e)
        {
            if(nums[s] < nums[e])
                return nums[s];
            
            int m = (s+e)/2;
            
            if(nums[m] >= nums[s])
                s = m+1;
            else
                e = m;
        }
        
        return nums[s];
    }
};