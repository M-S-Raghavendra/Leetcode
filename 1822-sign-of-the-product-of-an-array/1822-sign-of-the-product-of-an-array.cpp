class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int neg = 0;
        bool zero = false;
        
        for(auto x:nums)
        {
            if(x == 0)
            {
                zero = true;
                break;
            }
            else if(x < 0)
                neg++;
        }
        
        if(zero)
            return 0;
        else if(neg%2 == 0)
            return 1;
        else return -1;
    }
};