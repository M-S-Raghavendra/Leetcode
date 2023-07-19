class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {        
        vector<vector<pair<int,int>>> adj(n);
        vector<int> vis(n);
        for(auto x:connections)
        {
            adj[x[0]].push_back({x[1],1});
            adj[x[1]].push_back({x[0],2});
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            dfs(i,adj,vis,ans);
        }
        
        return ans;
    }
    
    void dfs(int s, vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &ans)
    {
        vis[s] = 1;
        for(auto x:adj[s])
        {
            if(!vis[x.first])
            {
                if(x.second == 1)
                    ans++;
                dfs(x.first,adj,vis,ans);
            }
        }
    }
};