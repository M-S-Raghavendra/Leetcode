class Solution {
private:
        int d[5] = {0,1,0,-1,0};
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n  =grid[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans = 0;
        
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0 and !vis[i][j])
                {
                    ans += bfs(i,j,grid,vis);
                }
            }
        }
        
        return ans;
    }
    
     int bfs(int i, int j, vector<vector<int>> &g, vector<vector<bool>> &v)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        v[i][j] = true;
        int ans = 0;
        bool bound =  false;
        
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nx = u.first + d[k];
                int ny = u.second + d[k+1];
                
                if(nx<0 or ny<0 or nx >= g.size() or ny >= g[0].size())
                {
                    bound = true;
                    continue;
                }
                
                if(g[nx][ny] == 0 and !v[nx][ny])
                {
                    q.push({nx,ny});
                    v[nx][ny] = true;
                }
            }
        }
        
        if(bound == false)
            ans++;
        
        return ans;
    }
};