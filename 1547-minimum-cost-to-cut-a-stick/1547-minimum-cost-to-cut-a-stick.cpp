class Solution {
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int cost = (cuts[j+1]-cuts[i-1]) + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(len+2,vector<int>(len+2,0));
        
        for(int i=len;i>=1;i--)
        {
            for(int j=i;j<=len;j++)
            {
                int mini = INT_MAX;
                for(int ind=i;ind<=j;ind++)
                {
                    int cost = (cuts[j+1]-cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][len];
    }
};