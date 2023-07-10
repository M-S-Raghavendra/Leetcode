class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        
        for(int i=1;i<=n;i++)
        {
            if(n % i == 0)
            {
                cnt++;https://leetcode.com/problems/the-kth-factor-of-n/discuss/
                if(cnt == k)
                    return i;
            }
        }
        
        return -1; 
    }
};