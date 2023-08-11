class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sm = accumulate(rolls.begin(),rolls.end(),0);
        
        int sn = mean*(n+m) - sm;
        
        if(sn < 0 or sn > 6*n) return {};
        vector<int> ans(n,1);
        
        int sum = sn - n;
        if(sum < 0) return {};
        
        for(int i=0;i<n;i++)
        {
            if(sum >= 5)
            {
                ans[i] += 5;
                sum -= 5;
            }
            else
            {
                ans[i] += sum;
                break;
            }
        }
        
        return ans;
    }
};