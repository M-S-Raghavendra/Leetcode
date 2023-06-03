class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> adj(n);
        int cnt = 0;
        
        // reverse the edges
        for(auto x:graph)
        {
            for(auto y:x)
            {
                adj[y].push_back(cnt);
            }
            cnt++;
        }
        
        // Topo sort using BFS or Kahn's algorithm
        for(auto x:adj)
            for(auto y:x)
                indegree[y]++;
        
        for(int i=0;i<n;i++)
            if(indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto x:adj[u])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};