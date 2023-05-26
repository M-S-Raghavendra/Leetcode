class Solution {
private:
    int f(int i, int m, bool alice, vector<int> &p, vector<vector<vector<int>>> &dp)
    {
        if(i == p.size())
            return 0;
        
        if(dp[i][m][alice] != -1) return dp[i][m][alice];
        
        int sum = 0;
        int ans = (alice) ? 0 : 1e9;
        
        for(int x=1;x<=(2*m);x++)
        {
            if(i+x-1 >= p.size())
                break;
            
            sum += p[i+x-1];
            
            if(alice)
            {
                ans = max(ans, sum + f(i+x,max(m,x),!alice,p,dp));
            }
            else
                ans = min(ans, f(i+x,max(m,x),!alice,p,dp));
        }
        
        return dp[i][m][alice] = ans;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        bool alice = true;
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2*n,vector<int>(2,-1)));
        return f(0,1,alice,piles,dp);
    }
};