class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0;
        int ans = INT_MIN;
        
        while(s < n and e < n)
        {
            int cnt = 0;
            while(e < n and nums[e] != 0)
            {
                cnt += (nums[e] < 0);
                e++;
            }
            
            if(cnt%2 == 0)
                ans = max(ans,e-s);
            else {
                int l = s, h = e-1;
                while(l<=h)
                {
                    if(nums[l] < 0)
                    {
                        ans = max(ans,e-l-1);
                        break;
                    }
                    if(nums[h] < 0)
                    {
                        ans = max(ans,h-s);
                        break;
                    }
                    l++;
                    h--;
                }
            }
            
            e++;
            s = e;
        }
        
        return ans;
    }
};