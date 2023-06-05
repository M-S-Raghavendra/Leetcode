class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int N = 1e9 + 7;
        // Dijkstra with ways array
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:roads)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            int node = it.second;
            
            for(auto x:adj[node])
            {
                int adjNode = x.first;
                int edgeW = x.second;
                
                if(d + edgeW < dist[adjNode])
                {
                    dist[adjNode] = d + edgeW;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(d + edgeW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % N; 
                }
            }
        }
        // for(auto x:ways)
        //     cout<<x<<" ";
        
        return ways[n-1];
    }
};