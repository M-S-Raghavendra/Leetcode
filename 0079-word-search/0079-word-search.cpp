class Solution {
private:
    int d[5] = {0,1,0,-1,0};
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(word[0] == board[i][j])
                {
                    if(dfs(i,j,1,word,board))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int i, int j, int k, string &word, vector<vector<char>> &board)
    {
        if(k == word.size())
            return true;
        
        char ch = board[i][j];
        board[i][j] = '#';  // visited
        
        for(int l=0;l<4;l++)
        {
            int ni = i + d[l];
            int nj = j + d[l+1];
            
            if(ni >= 0 and nj >= 0 and ni < board.size() and nj < board[0].size() and 
              board[ni][nj] == word[k])
            {
                if(dfs(ni,nj,k+1,word,board))
                    return true;
            }
        }
        
        board[i][j] = ch;
        return false;
    }
};