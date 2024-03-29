class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> a(n+1);
        for(auto x:roads)
        {
            a[x[0]].push_back({x[1],x[2]});
            a[x[1]].push_back({x[0],x[2]});
        }
        
        vector<bool> vis(n+1,false);
        unordered_set<int> l;
        
        dfs(1,a,vis,l);
        
        int ans = INT_MAX;
        
        for(auto x:roads)
        {
            if(l.find(x[0]) != l.end() and ans > x[2])
            {
                ans = x[2];
            }
        }
        
        return ans;
    }
    
    void dfs(int node, vector<vector<pair<int,int>>> &a, vector<bool> &vis, unordered_set<int> &l)
    {
        vis[node] = true;
        l.insert(node);
        
        for(auto neigh:a[node])
        {
            if(!vis[neigh.first])
            {
                dfs(neigh.first,a,vis,l);
            }
        }
    }
};