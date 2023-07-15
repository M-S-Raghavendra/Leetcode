class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        
        while(j < n)
        {
            while(j < n and sum < target)
                sum += nums[j++];
            
            if(sum >= target)
                ans = min(ans, j-i);
            
            while(i < j and sum >= target)
            {
                sum -= nums[i++];
                if(sum >= target)
                    ans = min(ans, j-i);
            }
        }
        
        if(ans == INT_MAX)
            return 0;
        
        return ans;
    }
};