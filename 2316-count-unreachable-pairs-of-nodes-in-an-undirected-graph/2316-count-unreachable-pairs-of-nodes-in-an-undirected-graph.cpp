class Solution {
private: 
        long long cnt=0;
public:
    
    void dfs(vector<vector<long long>>& adj, long long index, vector<bool>& vis)
    {
        vis[index] = true;
        cnt++;
        
        for(auto x:adj[index])
        {
            if(!vis[x])
            {
                dfs(adj, x, vis);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<long long>> adj(100001);
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<long long> ans;
        
        vector<bool> vis;
        vis.resize(n,false);
        
        for(long long i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        
        // for(auto x:ans)
        //     cout<<x<<" ";
        // cout<<endl;
        
        long long res = 0, sum = 0;
        
        for(long long i=0;i<ans.size();i++)
            sum += ans[i];
        
        for(long long i=0;i<ans.size();i++)
        {
            sum -= ans[i];
            res += ans[i]*sum;
        }
        
        return res;
    }
};