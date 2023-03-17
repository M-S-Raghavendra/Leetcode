class Solution {
private:
    int d[5] = {0,1,0,-1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans = 0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        
        ans += bfs(q,grid,vis);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        if(ans == -1) return 0;
        
        return ans;
    }
    
    int bfs(queue<pair<int,int>> &q, vector<vector<int>>& grid, vector<vector<bool>>& vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        while(!q.empty())
        {
            int count = q.size();
            
            for(int ii=0;ii<count;ii++)
            {
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                vis[x][y] = true;
                int nx, ny;

                for(int k=0;k<4;k++)
                {
                    nx = x + d[k];
                    ny = y + d[k+1];
                    
                    if(nx < 0 or ny < 0 or nx >= m or ny >= n)
                        continue;
                    if(!vis[nx][ny] and grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            
            ans++;
        }
        
        return ans-1;
    }
};