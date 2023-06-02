class Solution {
private:
    double getDistance(vector<int> &a, vector<int>& b)
    {
        double ans = 0;
        ans = sqrt((long)(b[0]-a[0])*(b[0]-a[0]) + (long)(b[1]-a[1])*(b[1]-a[1]));
        return ans;
    }
    
    int bfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        int cnt = 1;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto x:adj[u])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x] = 1;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j)
                {
                    double dist = getDistance(bombs[i],bombs[j]);
                    // cout<<dist<<" ";
                    if(dist <= (bombs[i][2]))
                        adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n);
            ans = max(ans, bfs(i,adj,vis));
        }
        
        return ans;
    }
};