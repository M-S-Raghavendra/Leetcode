class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        // vector<vector<int>> nextState(m,vector<int>(n));
        // vector<int> x = {1,1,1,0,0,-1,-1,-1};
        // vector<int> y = {-1,0,1,-1,1,-1,0,1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt = 0;
                // for(int k=0;k<8;k++)
                // {
                //     int nx, ny;
                //     nx = i + x[k];
                //     ny = j + y[k];
                //     if(nx<0 or nx>=m or ny<0 or ny>=n)
                //         continue;
                //     if(board[nx][ny] == 1) cnt++; 
                // }
                
                for(int I=max(i-1,0);I<min(i+2,m);I++)
                {
                    for(int J=max(j-1,0);J<min(j+2,n);J++)
                    {
                        cnt += board[I][J] & 1;
                    }
                }
                cnt -= board[i][j]; //bcz, board[i][j] is included and added in above loop
                
                if((cnt == 3) or (board[i][j] and (cnt == 2 or cnt == 3)))
                    board[i][j] |= 2;
                
                // if(cnt < 2) nextState[i][j] = 0;
                // if((cnt == 2 or cnt == 3) and board[i][j] == 1) nextState[i][j] = 1;
                // if(cnt > 3) nextState[i][j] = 0;
                // if(cnt == 3) nextState[i][j] = 1;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};