class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ctr(101,0);
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
            ctr[nums[i]]++;
        
        for(int i=1;i<101;i++)
            ctr[i] += ctr[i-1];
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                ans.push_back(0);
            else
                ans.push_back(ctr[nums[i]-1]);
        }
        
        return ans;
    }
};