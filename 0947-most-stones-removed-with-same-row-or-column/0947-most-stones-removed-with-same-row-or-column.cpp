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
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0;
        for(auto x:stones)
        {
            n = max(n,x[0]);
            m = max(m,x[1]);
        }
        n++;
        m++;
        DisjointSet ds(n+m);   // Columns are no.'s after rows, ex: rows->0,1,2 and cols->3.4,5
        int cntStones = stones.size();
        int comp = 0;
        int ans = 0;
        
        for(auto x:stones)
        {
            int row = x[0];
            int col = x[1];
            
            ds.unionBySize(row, n+1+col);
        }
        
        for(int i=0;i<(n+m);i++)
        {
            if(ds.par[i] == i and ds.size[i] > 1)
            {
                comp++;
            }
        }
        
        ans = cntStones - comp;
        return ans;
    }
};










