class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int n, int source, int destination)
    {
        vis[source] = true;
        
        if(source == destination)
            return ;
        
        for(auto child:adj[source])
        {
            if(!vis[child])
                dfs(adj,vis,n,child,destination);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]); 
            adj[x[1]].push_back(x[0]); 
        }
        
        dfs(adj,vis,n,source,destination);

        return (vis[destination]);
    }
};