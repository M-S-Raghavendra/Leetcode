class DSU {
private:
    vector<int> par, size;
public:
    DSU(int n) {
        par.resize(n+1);
        for(int i=1;i<=n;i++)
            par[i] = i;
        size.resize(n+1,0);
    }
    
    int findUPar(int u) {
        if(par[u] == u)
            return u;
        return par[u] = findUPar(par[u]);
    }
    
    int unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        
        if(pu == pv)
            return 0;
        if(size[pu] <= size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
        return 1;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n);
        
        for(auto x:edges)
        {
            int u = x[0];
            int v = x[1];
            
            if(ds.unionBySize(u,v) == 0)
                return x;
        }
        
        return {};
    }
};