class Solution {
private:
    void dfs(int node, vector<vector<int>> &g, vector<int> &path, vector<vector<int>> &ans)
    {
        path.push_back(node);
        
        if(node == g.size()-1)
            ans.push_back(path);
        
        for(auto nei:g[node])
            dfs(nei,g,path,ans);
        
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(0,graph,path,ans);
        return ans;
    }
};