class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        
        if(k <= numOnes)
            ans = k;
        else
        {
            ans += numOnes;
            k -= numOnes;
            
            if(k <= numZeros)
                return ans;
            else {
                k -= numZeros;
                ans -= k;
            }
        }
        
        return ans;
    }
};