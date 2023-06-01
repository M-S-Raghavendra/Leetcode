class Solution {
public:
    int d[9] = {1,0,-1,0,1,1,-1,-1,1};
    
    int f(int i, int j, vector<vector<int>> &g)
    {
        int n = g.size();
        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},1});
        g[i][j] = 2;
        
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            
            int x = u.first.first;
            int y = u.first.second;
            int l = u.second;
            
            if(x == n-1 and y == n-1)
                return l;
            
            for(int k=0;k<8;k++)
            {
                int nx = x + d[k];
                int ny = y + d[k+1];
                
                if(nx>=0 and ny>=0 and nx<n and ny<n)
                {
                    if(g[nx][ny] == 0)
                    {
                        q.push({{nx,ny},l+1});
                        g[nx][ny] = 2;
                    }
                }
            }
        }
        
        return -1;
    }
    
    // BFS
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
              
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1)
            return -1;
                
        return f(0,0,grid);
    }
};