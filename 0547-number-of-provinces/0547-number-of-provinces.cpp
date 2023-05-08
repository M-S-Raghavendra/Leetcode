class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, int n, vector<bool> &vis)
    {
        vis[node] = true;
        
        for(int i=0;i<n;i++)
        {
            if(adj[node][i] == 1 and node != i and !vis[i])
                dfs(i,adj,n,vis);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> vis(n+1);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,n,vis);
                count++;
            }
        }
        
        return count;
    }
};