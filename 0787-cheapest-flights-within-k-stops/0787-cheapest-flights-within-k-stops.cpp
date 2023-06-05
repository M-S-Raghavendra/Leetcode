class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:flights)
            adj[x[0]].push_back({x[1],x[2]});
        
        // {stops, {node,dist}}
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        int ans = 1e9;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int d = it.second.second;
            
            if(stops == k+1)
                continue;
            // else if(stops <= k+1 and node == dst)
            //     ans = min(ans,d);
            
            for(auto x:adj[node])
            {
                int adjNode = x.first;
                int edgeW = x.second;
                
                if(dist[adjNode] > d + edgeW)
                {
                    dist[adjNode] = d + edgeW;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        
        // for(auto x:dist)
        //     cout<<x<<" ";
        
        if(dist[dst] == 1e9)
            return -1;
        
        return dist[dst];
    }
};