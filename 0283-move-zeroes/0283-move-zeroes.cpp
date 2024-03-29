class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        
        while(i < n and j < n)
        {
            while(i < n and nums[i] != 0)
                i++;
            if(i == n) break;
            j = i+1;
            while(j < n and nums[j] == 0)
                j++;
            if(j == n) break;
            
            swap(nums[i],nums[j]);
        }
    }
};