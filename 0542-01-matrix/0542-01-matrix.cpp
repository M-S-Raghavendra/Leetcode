class Solution {
private:
    int d[5] = {0,1,0,-1,0};
    
    void bfs(queue<pair<pair<int,int>,int>> &q, vector<vector<int>> &mat, vector<vector<int>>& vis, vector<vector<int>>& ans)
    {
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            
            int i = u.first.first;
            int j = u.first.second;
            int dist = u.second;
            
            ans[i][j] = dist;
            
            for(int k=0;k<4;k++)
            {
                int nx = i + d[k];
                int ny = j + d[k+1];

                if(nx<0 or ny<0 or nx>=mat.size() or ny>=mat[0].size())
                    continue;
                
                if(mat[nx][ny] == 1 and !vis[nx][ny])
                {
                    q.push({{nx,ny},dist+1});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    
public:
    // BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,0)), vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        bfs(q,mat,vis,ans);
        
        return ans;
    }
};