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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        
        for(auto x:connections)
        {
            int u = x[0];
            int v = x[1];
            
            if(ds.findUPar(u) == ds.findUPar(v))
                extra++;
            
            ds.unionBySize(u,v);
        }
        
        int comp = 0;
        for(int i=0;i<n;i++)
            if(ds.par[i] == i)
                comp++;
        
        int ans = comp-1;
        
        if(extra >= ans)
            return ans;
        else return -1;
    }
};









