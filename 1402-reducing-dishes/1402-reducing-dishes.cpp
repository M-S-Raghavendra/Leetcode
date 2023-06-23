class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        int total = 0, ans = 0;
        
        sort(satisfaction.begin(),satisfaction.end());
        
        for(int i=n-1;i>=0 and (satisfaction[i]+total > 0);i--)
        {
            total += satisfaction[i];
            ans += total;
        }
        
        return ans;
    }
};