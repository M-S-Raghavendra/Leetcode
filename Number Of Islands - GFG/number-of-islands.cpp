//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int d[5] = {0,1,0,-1,0};
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<int> ans;
        int curcell, adjcell;
        int cnt = 0;
        
        for(auto x:operators)
        {
            if(grid[x[0]][x[1]] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            grid[x[0]][x[1]] = 1;
            cnt++;
            curcell = x[0]*m + x[1];
            
            for(int k=0;k<4;k++)
            {
                int nrow = x[0] + d[k];
                int ncol = x[1] + d[k+1];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol] == 1)
                {
                    adjcell = nrow*m + ncol;
                    if(ds.findUPar(curcell) != ds.findUPar(adjcell))
                    {
                        ds.unionBySize(curcell,adjcell);
                        cnt--;
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};










//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends