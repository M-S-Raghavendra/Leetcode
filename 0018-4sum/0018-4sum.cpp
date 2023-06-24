class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4)
            return {};
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int a = 0, b;
        int c, d;
        
        while(a < n)
        {
            b = a+1;
            while(b < n) 
            {
                c = b+1;
                d = n-1;
                while(c < d)
                {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum == target) {
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++, d--;
                        while(c < d and nums[c] == nums[c-1]) c++;
                        while(c < d and nums[d] == nums[d+1]) d--;
                    }
                    else if(sum < target) {
                        c++;
                    }
                    else {
                        d--;
                    }
                }
                b++;
                while(b < n and nums[b] == nums[b-1]) b++;
            }
            a++;
            while(a < n and nums[a] == nums[a-1]) a++;
        }
        
        return ans;
    }
};