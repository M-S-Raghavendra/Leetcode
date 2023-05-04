class Solution {
private:
    int d[5] = {0,1,0,-1,0};
    
    void bfs(int i, int j, vector<vector<char>> &b, vector<vector<bool>> &vis)
    {
        int m = b.size();
        int n = b[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;
        
        vector<pair<int,int>> v;
        bool boundary = false;
        
        while(!q.empty())
        {
            pair<int,int> u = q.front();
            q.pop();
            v.push_back({u.first,u.second});
            
            for(int k=0;k<4;k++)
            {
                int nx = u.first + d[k];
                int ny = u.second + d[k+1];
                
                if(nx<0 or ny<0 or nx>=m or ny>=n)
                {
                    boundary = true;
                    continue;
                }
                if(b[nx][ny] == 'O' and !vis[nx][ny])
                {
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
        
        if(!boundary)
        {
            for(auto x:v)
            {
                b[x.first][x.second] = 'X';
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O' and !vis[i][j])
                {
                    bfs(i,j,board,vis);
                }
            }
        }
    }
};