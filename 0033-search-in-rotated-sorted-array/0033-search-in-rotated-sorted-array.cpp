class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        
        while(s <= e)
        {
            int m = (s+e)/2;
            if(nums[m] == target)
                return m;
            if(nums[m] >= nums[s])
            {
                if(target > nums[m])
                    s = m+1;
                else {
                    if(target >= nums[s])
                        e = m;
                    else
                        s = m+1;
                }
            }
            else {
                if(target < nums[m])
                    e = m;
                else {
                    if(target < nums[s])
                        s = m+1;
                    else
                        e = m;
                }
            }
        }
        
        return -1;
    }
};