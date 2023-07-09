class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> v(n,s);
        vector<int> pos(n,-1);
        
        nQueens(0,n,pos,v,ans);
        return ans;
    }
    
    void nQueens(int r, int n, vector<int> &pos, vector<string> &v, vector<vector<string>> &ans)
    {
        if(r == n)
        {
            for(int i=0;i<n;i++)
                v[i][pos[i]] = 'Q';
            ans.push_back(v);
            for(int i=0;i<n;i++)
                v[i][pos[i]] = '.';
            return;
        }
        
        for(int c=0;c<n;c++)
        {
            if(canPlace(r,c,pos))
            {
                pos[r] = c;
                nQueens(r+1,n,pos,v,ans);
                pos[r] = -1;
            }
        }
    }
    
    bool canPlace(int r, int c, vector<int> &pos)
    {
        for(int j=0;j<r;j++)
        {
            if(c == pos[j] or abs(r-j) == abs(c-pos[j]))
                return false;
        }
        return true;
    }
};