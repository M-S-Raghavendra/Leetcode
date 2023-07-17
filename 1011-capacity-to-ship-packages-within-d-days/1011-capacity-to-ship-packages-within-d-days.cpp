class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *max_element(weights.begin(),weights.end());
        int e = 0;
        for(auto x:weights)
            e += x;
        
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(check(weights,m,days))
                e = m-1;
            else
                s = m+1;
        }
        return s;
    }
    
    bool check(vector<int> &w, int m, int days)
    {
        int sum = 0;
        int ans = 0;
        for(auto x:w)
        {
            if(sum + x <= m)
                sum += x;
            else {
                sum = x;
                ans++;
            }
        }
        ans++;
        
        return (ans <= days);
    }
};