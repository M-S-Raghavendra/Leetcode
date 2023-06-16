class Solution {
public:
    int removeDuplicates(vector<int>& nums) {        
        int n = nums.size();
        int i = 1, j = 1;
        
        while(i < n and j < n)        
        {
            if(nums[i] != nums[i-1])
            {
                nums[j] = nums[i];
                i++;
                j++;
            }
            else
                i++;
        }
        
        return j;
    }
};