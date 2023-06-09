class DisjointSet {
    vector<int> size, par;
public:
    DisjointSet(int n) {
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
            par[i] = i;
    }
    
    int findUPar(int u) {
        if(par[u] == u)
            return u;
        return par[u] = findUPar(par[u]);
    }
    
    void unionBySize(int u, int v) {
        int upu = findUPar(u);
        int upv = findUPar(v);
        if(upu == upv)
            return;
        if(size[upu] < size[upv]) {
            par[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            par[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution {
private:
//     void dfs(int node, vector<vector<int>> &adj, int n, vector<bool> &vis)
//     {
//         vis[node] = true;
        
//         for(int i=0;i<n;i++)
//         {
//             if(adj[node][i] == 1 and node != i and !vis[i])
//                 dfs(i,adj,n,vis);
//         }
//     }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Using DSU
        int n = isConnected.size();
        DisjointSet ds(n+1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    int node = i+1;
                    int adjNode = j+1;

                    if(ds.findUPar(node) != ds.findUPar(adjNode))
                    {
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(ds.findUPar(i) == i)
                cnt++;
        }
        
        return cnt;
        
        // Using DFS/BFS
//         int n = isConnected.size();
//         int count = 0;
//         vector<bool> vis(n+1);
        
//         for(int i=0;i<n;i++)
//         {
//             if(!vis[i])
//             {
//                 dfs(i,isConnected,n,vis);
//                 count++;
//             }
//         }
        
//         return count;
    }
};