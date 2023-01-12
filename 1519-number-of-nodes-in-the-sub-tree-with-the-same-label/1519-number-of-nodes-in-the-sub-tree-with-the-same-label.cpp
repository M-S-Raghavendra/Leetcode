class Solution {
private:
    unordered_map<char,vector<int>> m;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {        
        vector<vector<int>> a(n);
        for(auto x:edges)
        {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
        
        vector<bool> vis(n);
        vector<int> ans(n,1);
        
        dfs(n,a,labels,vis,ans,0);
        return ans;
    }
    
    void dfs(int n, vector<vector<int>> &a, string &labels, vector<bool> &vis, vector<int> &ans, int ind)
    {
        vis[ind] = true;
        
        if(m.find(labels[ind]) == m.end())
            m.insert({labels[ind],{ind}});
        else
            m[labels[ind]].push_back(ind);
            
        for(auto node:a[ind])
        {
            if(!vis[node])
            {
                if(m.find(labels[node]) != m.end())
                {
                    for(auto x:m[labels[node]])
                            ans[x]++;
                }
                dfs(n,a,labels,vis,ans,node);
            }
        }
        m[labels[ind]].pop_back();
    }
};