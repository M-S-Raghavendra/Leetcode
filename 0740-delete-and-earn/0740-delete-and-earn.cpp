class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x] += x;
        
        int skip = 0, take = 0;
        
        for(int i=0;i<n;i++)
        {
            int takei = skip + m[i];
            int skipi = max(skip,take);
            take = takei;
            skip = skipi;
        }
        
        return max(skip,take);
    }
};