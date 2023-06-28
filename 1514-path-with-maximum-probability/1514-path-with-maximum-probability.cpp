class Solution {
    typedef pair<double,int> pd;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pd> pq;
        vector<double> dist(n,(double)0.0);
        dist[start] = 1;
        vector<int> vis(n);
        pq.push({(double)1.0,start});
        
        while(!pq.empty())
        {
            auto x = pq.top();
            double prob = x.first;
            int node = x.second;
            pq.pop();
            
            if(!vis[node]) {
                vis[node] = 1;
                for(auto v:adj[node]) {
                    if(dist[v.first] < prob * v.second) {
                        dist[v.first] = prob * v.second;
                        pq.push({dist[v.first],v.first});
                    }
                }
            }
        }
        
        return dist[end];
    }
};