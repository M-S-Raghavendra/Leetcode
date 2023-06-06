class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x:times)
            adj[x[0]].push_back({x[1],x[2]});
        
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;
            
            for(auto x:adj[node])
            {
                int adjNode = x.first;
                int edgeW = x.second;
                
                if(dist[adjNode] > d + edgeW)
                {
                    dist[adjNode] = d + edgeW;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        int minTime = *max_element(dist.begin()+1,dist.end());
        // dist.begin() + 1, +1 bcz 1-based indexing of nodes
        if(minTime == 1e9)
            return -1;
        return minTime;
    }
};