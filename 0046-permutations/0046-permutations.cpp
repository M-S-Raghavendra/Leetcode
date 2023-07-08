class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(0,nums,ans);
        return ans;
    }
    
    void f(int i, vector<int>&nums, vector<vector<int>> &ans)
    {
        if(i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            f(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
};