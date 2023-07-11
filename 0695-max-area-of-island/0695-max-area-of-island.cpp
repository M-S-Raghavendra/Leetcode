class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, bfs(i,j,grid));
                }
            }
        }
        
        return ans;
    }
    
    int bfs(int i, int j, vector<vector<int>> &g)
    {
        int d[5] = {0,1,0,-1,0};
        int m = g.size();
        int n = g[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        g[i][j] = 0;
        int cnt = 1;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nx = x + d[k];
                int ny = y + d[k+1];
                
                if(nx>=0 and ny>=0 and nx<m and ny<n and g[nx][ny] == 1)
                {
                    q.push({nx,ny});
                    g[nx][ny] = 0;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};