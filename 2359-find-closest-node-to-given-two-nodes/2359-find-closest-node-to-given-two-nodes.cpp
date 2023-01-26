class Solution {
public:
    void bfs(vector<int>& edges, int node, vector<pair<bool,bool>>& vis, vector<pair<int,int>>& dist, int num)
    {
        int cnt=0;
        (num == 1) ? vis[node].first = true : vis[node].second = true;
        queue<int> q;
        q.push(node);
        
        if(num == 1)
            dist[node].first = 0;
        else
            dist[node].second = 0;
        
        while(!q.empty())
        {
            cnt++;
            auto u = q.front(); q.pop();
            int adj = edges[u];
            
            if(adj != -1 and ((num==1 and !vis[adj].first) or (num==2 and !vis[adj].second)))
            {
                q.push(adj);
                (num == 1) ? vis[adj].first=true : vis[adj].second=true;
                if(num == 1)
                    dist[adj].first = cnt;
                else
                    dist[adj].second = cnt;            
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<pair<bool,bool>> vis(n,{false,false});
        vector<pair<int,int>> dist(n,{-1,-1});
        int res = INT_MAX;
        
        bfs(edges,node1,vis,dist,1);
        bfs(edges,node2,vis,dist,2);
        
        // for(auto x:vis)
        //     cout<<x.first<<" "<<x.second<<"\n";
        // cout<<endl;
        // for(auto x:dist)
        //     cout<<x.first<<" "<<x.second<<"\n";
        
        int temp, index = -1;
        
        for(int i=0;i<dist.size();i++)
        {
            if(vis[i].first and vis[i].second)
            {
                temp = res;
                res = min(res, max(dist[i].first, dist[i].second));
                if(res != temp)
                    index = i;
            }
        }
    
        return index;
    }
};