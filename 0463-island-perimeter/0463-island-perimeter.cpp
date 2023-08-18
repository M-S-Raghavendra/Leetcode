class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int d[5] = {0,1,0,-1,0};
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        bool flag = false;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        int ans = 0;
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            ans += 4;

            for(int k=0;k<4;k++)
            {
                int ni = i+d[k];
                int nj = j+d[k+1];
                
                if(ni>=0 and nj>=0 and ni<m and nj<n)
                {
                    if(grid[ni][nj] == 1)
                        ans--;
                    if(!vis[ni][nj] and grid[ni][nj] == 1)
                    {
                        q.push({ni,nj});
                        vis[ni][nj] = 1;
                    }
                }
            }
        }
        
        return ans;
    }
};