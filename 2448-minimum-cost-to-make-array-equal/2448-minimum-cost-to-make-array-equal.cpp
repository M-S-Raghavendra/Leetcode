class Solution {
public:
    long long f(int eqval, vector<int> &nums, vector<int> &cost)
    {
        long long ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans += (long long)abs(nums[i]-eqval)*cost[i];
        }
        
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = 1e15;
        int s = 1, e = 1000000;
        
        while(s <= e)
        {
            long long m = (s + e)/2;
            long long v1 = f(m,nums,cost);
            long long v2 = f(m+1,nums,cost);
            ans = min(v1,v2);
            
            if(v1 < v2) {   // go left
                e = m-1;
            }
            else {          // go right
                s = m+1;
            }
        }
        
        return ans;
    }
};