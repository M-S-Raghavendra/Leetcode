class DisjointSet {
public:
    vector<int> size, par;
    
    DisjointSet(int n) {
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findUPar(int node) {
        if (node == par[node])
            return node;
        return par[node] = findUPar(par[node]);
    }

    void unionBySize(int u, int v) {
        int upu = findUPar(u);
        int upv = findUPar(v);
        if (upu == upv) return;
        if (size[upu] < size[upv]) {
            par[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            par[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int d[5] = {0,1,0,-1,0};
        int zero = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {                    
                    for(int k=0;k<4;k++)
                    {
                        int ni = i + d[k];
                        int nj = j + d[k+1];
                        
                        if(ni>=0 and nj>=0 and ni<n and nj<n and grid[ni][nj] == 1)
                        {
                            int cell = i*n + j;
                            int adjcell = ni*n + nj;
                            
                            if(ds.findUPar(cell) != ds.findUPar(adjcell))
                            {
                                ds.unionBySize(cell,adjcell);
                            }
                        }
                    }
                }
                else
                    zero++;
            }
        }
        
        if(zero == 0)
            return n*n;
         
        int ans = 0;
            
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {                    
                    unordered_set<int> s;
                    for(int k=0;k<4;k++)
                    {
                        int ni = i + d[k];
                        int nj = j + d[k+1];
                        
                        if(ni>=0 and nj>=0 and ni<n and nj<n and grid[ni][nj] == 1)
                        {
                            int adjcell = ni*n + nj;
                            
                            s.insert(ds.findUPar(adjcell));
                        }
                    }
                    int sum = 0;
                    for(auto x:s)
                        sum += ds.size[x];
                    sum++;
                    
                    ans = max(ans,sum);
                }
            }
        }
        
        return ans;
    }
};