class Solution {
private:
    bool bfs(int src, vector<vector<int>> &g, vector<int>& col)
    {
        queue<int> q;
        q.push(src);
        col[src] = 0;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto x:g[u])
            {
                if(col[x] == -1)
                {
                    q.push(x);
                    col[x] = (col[u] == 0) ? 1 : 0;
                }
                else {
                    if(col[x] == col[u])
                        return false;
                }
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++)            
        {
            if(col[i] == -1)
                if(bfs(i,graph,col) == false)
                    return false;
        }
        
        return true;
    }
};