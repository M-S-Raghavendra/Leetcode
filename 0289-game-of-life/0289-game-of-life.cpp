class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> nextState(m,vector<int>(n));
        
        vector<int> x = {1,1,1,0,0,-1,-1,-1};
        vector<int> y = {-1,0,1,-1,1,-1,0,1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt = 0;
                for(int k=0;k<8;k++)
                {
                    int nx, ny;
                    nx = i + x[k];
                    ny = j + y[k];
                    if(nx<0 or nx>=m or ny<0 or ny>=n)
                        continue;
                    if(board[nx][ny] == 1) cnt++; 
                }
                
                if(cnt < 2) nextState[i][j] = 0;
                if((cnt == 2 or cnt == 3) and board[i][j] == 1) nextState[i][j] = 1;
                if(cnt > 3) nextState[i][j] = 0;
                if(cnt == 3) nextState[i][j] = 1;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // cout<<nextState[i][j];
                board[i][j] = nextState[i][j];
            }
        }
    }
};