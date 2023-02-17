class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        
        while(s <= e)
        {
            int m = (s+e)/2;
            
            if((m == n-1 or nums[m] != nums[m+1]) and (m == 0 or nums[m] != nums[m-1]))
                return nums[m];
            else if(m!=0 and nums[m] == nums[m-1]) {
                if(m%2 == 0)
                    e = m-2;
                else 
                    s = m+1;
            }
            else if(m!=n-1 and nums[m] == nums[m+1]) {
                if(m%2 == 1)
                    e = m-1;
                else 
                    s = m+2;
            }
        }
        
        return -1;
    }
};