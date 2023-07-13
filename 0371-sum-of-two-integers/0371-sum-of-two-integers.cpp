class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        
        for(int i=0;i<32;i++)
        {
            int aa = (a&(1<<i));
            int bb = (b&(1<<i));
            
            if(carry == 1) {
                if(aa and bb)
                {
                    ans = (ans | (1<<i));
                    carry = 1;
                }
                else if(aa or bb)
                    carry = 1;
                else {
                    ans = (ans | (1<<i));
                    carry = 0;
                }
            }
            else {
                if(aa and bb)
                    carry = 1;
                else if(aa or bb)
                    ans = (ans | (1<<i));
            }
        }
        
        return ans;
    }
};