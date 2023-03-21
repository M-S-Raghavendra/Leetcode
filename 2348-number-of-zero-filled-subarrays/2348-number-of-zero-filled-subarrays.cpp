class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        
        long long s=0, e=0;
        long long n = nums.size();
        
        while(e < n)
        {
            long long count = 0;
            
            if(nums[e] == 0)
                s = e;
            
            while(e < n and nums[e] == 0)
            {
                count++;
                e++;
            }
            
            if(count)
            {
                long long temp = e-s;
                ans += (temp*(temp+1))/2;
            }
            e++;
        }
        
        return ans;
    }
};