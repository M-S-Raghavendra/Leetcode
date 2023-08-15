class NumMatrix {
public:
    vector<vector<int>> p;
    
    NumMatrix(vector<vector<int>>& matrix) {
        p = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                p[i][j] = p[i][j] + p[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                p[j][i] = p[j][i] + p[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int tot = p[row2][col2];
        if(col1-1 >= 0)
            tot -= p[row2][col1-1];
        if(row1-1 >= 0)
            tot -= p[row1-1][col2];
        if(row1-1 >= 0 and col1-1 >= 0)
            tot += p[row1-1][col1-1];
        return tot;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */