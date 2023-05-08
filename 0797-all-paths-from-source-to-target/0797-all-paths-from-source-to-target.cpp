class Solution {
private:
    void dfs(int node, vector<vector<int>> &g, vector<int> &path, vector<vector<int>> &ans, vector<bool> &vis)
    {
        if(node == g.size()-1)
        {
            path.push_back(node);
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        
        vis[node] = true;
        path.push_back(node);
        
        for(auto nei:g[node])
        {
            if(!vis[nei])
                dfs(nei,g,path,ans,vis);
        }
        
        path.pop_back();
        vis[node] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> vis(n);
        
        dfs(0,graph,path,ans,vis);
        return ans;
    }
};