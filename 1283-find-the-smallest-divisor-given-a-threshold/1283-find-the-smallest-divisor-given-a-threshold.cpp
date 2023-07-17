class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1, e = *max_element(nums.begin(),nums.end());
        
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(check(nums,m,threshold))
                e = m-1;
            else
                s = m+1;
        }
        
        return s;
    }
    
    bool check(vector<int> &nums, int m, int th)
    {
        int sum = 0;
        for(auto x:nums)
            sum += ceil((double)x/(double)m);
        return (sum  <= th);
    }
};