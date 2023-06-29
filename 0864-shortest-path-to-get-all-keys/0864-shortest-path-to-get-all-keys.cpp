class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // {i,j,keysPicked}
        queue<vector<int>> q;
        // bitmap of 6 bits, to check if ith key is picked or not
        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(64,0)));
        
        int st, e, keys = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] >= 'a' and grid[i][j] <= 'z')
                    keys++;
                else if(grid[i][j] == '@')
                    st = i, e = j;
            }
        
        q.push({st,e,0});
        vis[st][e][0] = 1;
        int d[5] = {0,1,0,-1,0};
        
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int cnt=0;cnt<sz;cnt++)
            {
                auto u = q.front();
                q.pop();
                int i = u[0];
                int j = u[1];
                int picked = u[2];

                // cout<<i<<" "<<j<<" "<<ky<<endl;

                if(picked == (1<<keys)-1)
                    return steps;

                for(int k=0;k<4;k++)
                {
                    int ni = i + d[k];
                    int nj = j + d[k+1];
                    int newPicked = picked;
                    
                    if(ni>=0 and nj>=0 and ni<m and nj<n and grid[i][j] != '#') 
                    {
                        if(grid[ni][nj] >= 'a' and grid[ni][nj] <= 'z')
                        {
                            newPicked = picked | (1<<(grid[ni][nj]-'a'));
                        }
                        else if(grid[ni][nj] >= 'A' and grid[ni][nj] <= 'Z')
                        {
                            if(!(picked & (1<<(grid[ni][nj]-'A'))))
                                continue;
                        }
                        if(!vis[ni][nj][newPicked])
                        {
                            vis[ni][nj][newPicked] = 1;
                            q.push({ni,nj,newPicked});
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};