class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        unordered_map<int,int> m;
        int n = events.size();
        sort(events.begin(),events.end());
        
        for(int i=0;i<n;i++)
        {
            // int ind = -1;
            for(int j=i+1;j<n;j++)
            {
                if(events[i][1] < events[j][0])
                {
                    m[i] = j;
                    break;
                }
            }
            if(m.find(i) == m.end())
                m[i] = n;
        }
        
//         for(auto x:m)
//             cout<<x.first<<" "<<x.second<<endl;
//         for(auto x:events)
//             cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(0,k,events,m,dp);
    }
    
    int f(int i, int k, vector<vector<int>> &e, unordered_map<int,int> &m, vector<vector<int>> &dp)
    {
        if(i == e.size())
            return 0;
        if(k == 0)
            return 0;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int notpick = 0 + f(i+1,k,e,m,dp);
        // int next = bsearch(e,i,i+1,e.size()-1);
        int pick = e[i][2] + f(m[i],k-1,e,m,dp);
        // cout<<i<<" "<<notpick<<" "<<pick<<endl;
        
        return dp[i][k] = max(pick,notpick);
    }
    
    int bsearch(vector<vector<int>> &ev, int i, int s, int e)
    {
        int ans = ev.size();
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(ev[i][1] < ev[m][0])
            {
                ans = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        
        return ans;
    }
};