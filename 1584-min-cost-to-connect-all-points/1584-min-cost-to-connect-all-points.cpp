class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        
        vector<int> vis(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        int ans = 0;
        
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            
            if(vis[i]) continue;
            
            vis[i] = 1;
            ans += cost;
            
            for(auto x:adj[i])
            {
                if(!vis[x.first])
                {
                    pq.push({x.second,x.first});
                }
            }
        }
        
        return ans;
    }
};