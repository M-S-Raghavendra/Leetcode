class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = n-1;
        int i = n-2;
        
        while(i >= 0 and nums[i] >= nums[i+1])
            i--;
        if(i < 0)
            reverse(nums.begin(),nums.end());
        else {
            while(ind >= 0 and nums[ind] <= nums[i])
                ind--;
            swap(nums[i],nums[ind]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};