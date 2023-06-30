class Solution {
public:
    bool canWalk(int row, int col, vector<vector<int>> &cells, int day)
    {
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<day;i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++)
            if(grid[0][i] == 0)
            {
                q.push({0,i});
                grid[0][i] = 1;
            }
        
        int d[5] = {0,1,0,-1,0};
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            if(x == row-1)
                return true;
            
            for(int k=0;k<4;k++)
            {
                int nx = x + d[k];
                int ny = y + d[k+1];
                
                if(nx>=0 and ny>=0 and nx<row and ny<col and grid[nx][ny] == 0)
                {
                    q.push({nx,ny});
                    grid[nx][ny] = 1;
                }
            }
        }
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s = 0, e = row*col;
        int days = 0;
        
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(canWalk(row,col,cells,m))
            {
                days = m;
                s = m+1;
            }
            else
                e = m-1;
        }
        
        return days;
    }
};