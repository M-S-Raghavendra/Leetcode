class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        int i = 0, j, k;
        
        while(i < n)
        {
            j = i+1;
            k = n-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++, k--;
                    while(j < k and nums[j] == nums[j-1]) j++;
                    while(k > j and nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0) {
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
            }
            
            i++;
            while(i < n and nums[i] == nums[i-1]) i++;
        }
        
        return ans;
        
    }
};