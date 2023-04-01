class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n,vector<int>(367,-1));
        int ans = f(n-1,days[n-1]+1,days,costs,dp);
        
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        
        return ans;
    }
    
    int f(int i, int valid, vector<int>& d, vector<int>& c, vector<vector<int>>& dp)
    {
        if(i < 0)
            return 0;
        if(valid < 0)
            valid = 0;
        
        if(dp[i][valid] != -1)
            return dp[i][valid];
        
        if(d[i] >= valid)
            return dp[i][valid] = f(i-1,valid,d,c,dp);
        
        int daily = c[0] + f(i-1,d[i],d,c,dp);
        int weekly = c[1] + f(i-1,d[i]-7+1,d,c,dp);
        int monthly = c[2] + f(i-1,d[i]-30+1,d,c,dp);
        
        return dp[i][valid] = min(daily,min(weekly,monthly));
    }
};