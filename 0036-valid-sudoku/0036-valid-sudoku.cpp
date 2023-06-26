class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int seenRow[9][9] = {0}, seenCol[9][9] = {0}, seenSubBox[9][9] = {0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3 * 3 + j/3; 
                    
                    if(seenRow[i][num] or seenCol[j][num] or seenSubBox[k][num])
                        return false;
                    seenRow[i][num] = seenCol[j][num] = seenSubBox[k][num] = 1;
                }
            }
        }
        return true;
    }
};