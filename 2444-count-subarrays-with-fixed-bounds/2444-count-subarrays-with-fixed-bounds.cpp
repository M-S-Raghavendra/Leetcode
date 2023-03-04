class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = 0, minFound = false, maxFound = false;
        int n = nums.size();
        int minStart = 0, maxStart = 0;
        long long  ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] < minK or nums[i] > maxK)
            {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            
            if(nums[i] == minK)
            {
                minFound = true;
                minStart = i;
            }
            
            if(nums[i] == maxK)
            {
                maxFound = true;
                maxStart = i;
            }
            
            if(minFound and maxFound)
            {
                ans += min(minStart,maxStart) - start + 1;
            }
        }
        
        return ans;
    }
};