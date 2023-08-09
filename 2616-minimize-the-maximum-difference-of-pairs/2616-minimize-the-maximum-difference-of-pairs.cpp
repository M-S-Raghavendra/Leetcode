class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int s = 0, e = nums[n-1]-nums[0];
        
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(check(m,nums,p))
                e = m-1;
            else
                s = m+1;
        }
        
        return s;
    }
    
    bool check(int m, vector<int> &nums, int p)
    {
        int cnt = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1] <= m)
            {
                cnt++;
                i++;
            }
        }
        
        return (cnt >= p);
    }
};