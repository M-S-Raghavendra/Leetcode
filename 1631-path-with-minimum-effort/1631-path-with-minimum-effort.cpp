class Solution {
    typedef pair<int,pair<int,int>> pp;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int dir[5] = {0,1,0,-1,0};
        
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0] = 0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int row = p.second.first;
            int col = p.second.second;
            
            if(row == m-1 and col == n-1)
                return d;
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + dir[i];
                int ncol = col + dir[i+1];
                
                if(nrow>=0 and ncol>=0 and nrow<m and ncol<n)
                {
                    int diff = abs(heights[nrow][ncol] - heights[row][col]);
                    int cost = max(d,diff);
                    if(cost < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = cost;
                        pq.push({dist[nrow][ncol], {nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
    }
};