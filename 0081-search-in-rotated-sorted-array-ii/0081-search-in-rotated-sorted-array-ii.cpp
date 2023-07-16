class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(nums[m] == target)
                return true;
            // Extra case for handling duplicates at s,m,e
            // nums[s] == nums[m] == nums[e]
            if(nums[s] == nums[m] and nums[m] == nums[e])
                s++, e--;
            else if(nums[s] <= nums[m])
            {
                if(nums[s] <= target and target <= nums[m])
                    e = m-1;
                else
                    s = m+1;
            }
            else {
                if(nums[m] <= target and target <= nums[e])
                    s = m+1;
                else
                    e = m-1;
            }
        }
        
        return false;
    }
};