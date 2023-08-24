class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++)
            if(!color[i])
                if(!dfs(i,graph,color,1))
                    return false;
        
        return true;
    }
    
    bool dfs(int s, vector<vector<int>> &g, vector<int> &color, int col)
    {
        color[s] = col;
        
        for(auto x:g[s])
        {
            if(!color[x]) {
                if(!dfs(x,g,color,-col))
                    return false;
            }
            else if(color[x] == color[s])
                return false;
        }
        
        return true;
    }
};