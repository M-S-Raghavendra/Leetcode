class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> vis(n,false);
        
        q.push(0);
        vis[0] = true;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto v:rooms[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for(auto x:vis)
            if(x)
                ans++;
        
        return ans==n;
    }
};