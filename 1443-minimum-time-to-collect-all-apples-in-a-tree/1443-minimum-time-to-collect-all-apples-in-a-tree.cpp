class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans = 0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n);
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        bool res = dfs(n,adj,hasApple,vis,ans,0);
        if(ans == -1) return 0;
        else return --ans;
    }

    bool dfs(int n, vector<vector<int>> &a, vector<bool> &hasApple, vector<bool>& vis, int &ans, int ind)
    {
        vis[ind] = true;
        bool sub = false, yes = false;
        
        for(auto node:a[ind])
        {
            if(!vis[node])
            {
                ans++;
                sub = false;
                sub = dfs(n,a,hasApple,vis,ans,node);
                if(sub)
                {
                    yes = true;
                }
            }
        }
        
        if(yes or hasApple[ind]) ans++;
        else ans--;
        // cout<<ans<<" ";
        return yes or hasApple[ind];
    }
};