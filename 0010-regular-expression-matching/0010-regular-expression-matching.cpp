class Solution {
public:
    vector<vector<int>> dp;
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        dp.resize(n,vector<int>(m,-1));
        
        return f(n-1,m-1,s,p);
    }
    
    bool f(int i, int j, string &a, string &b)
    {
        if(i < 0 and j < 0) return true;
        if(i < 0) {
            for(int k=j;k>=0;k-=2)
                if(b[k] != '*') return false;
            return true;
        }
        if(j < 0) {
            for(int k=i;k>=0;k-=2)
                if(a[k] != '*') return false;
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j])
            return dp[i][j] = f(i-1,j-1,a,b);
        if(b[j] == '.')
            return dp[i][j] = f(i-1,j-1,a,b);
        if(b[j] == '*')
        {
            if(b[j-1] == a[i] or b[j-1] == '.')
                return dp[i][j] = f(i-1,j-2,a,b) or f(i-1,j,a,b) or f(i,j-2,a,b);
            else
                return dp[i][j] = f(i,j-2,a,b);
        }
        return dp[i][j] = false;
    }
};