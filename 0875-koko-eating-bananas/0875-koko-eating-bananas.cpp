class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = INT_MAX;
        int ans = 0;
        
        while(s <= e)
        {
            int m = s + (e-s)/2;
            
            if(check(piles,m) <= h)
            {
                ans = m;
                e= m-1;
            }
            else
                s = m+1;
        }
        
        return ans;
    }
    
    long long check(vector<int> &p, int m)
    {
        long long res = 0;
        for(auto x:p)           
            res += (long long)ceil((1.0*x)/m);
        return res;            
    }
};