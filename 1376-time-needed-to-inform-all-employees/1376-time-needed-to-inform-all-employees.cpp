class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i] != -1)
            {
                adj[manager[i]].push_back({i,informTime[manager[i]]});
            }
        }
        
        queue<pair<int,int>> q;
        int ans = 0;
        q.push({0,headID});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int time = it.first;
            int node = it.second;
            ans = max(ans,time);
            
            for(auto x:adj[node])
            {
                int sub = x.first;
                int infoTime = x.second;
                
                q.push({time + infoTime, sub});
            }
        }
        
        return ans;
    }
};