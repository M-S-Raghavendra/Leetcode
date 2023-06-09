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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans, merged(n);
        unordered_map<string,int> m;
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(auto y:accounts[i])
            {
                if(cnt == 0)
                {
                    cnt++;
                    continue;
                }
                if(m.find(y) != m.end())
                {
                    int u = i;
                    int v = m[y];
                    ds.unionBySize(u,v);
                }
                else {
                    m[y] = i;
                }
            }
        }
        
        for(auto x:m)
        {
            int i = x.second;
            string email = x.first;
            
            int index = ds.findUPar(i);
            merged[index].push_back(email);
        }
        
        for(auto &x:merged)     // If there is '&', then only sorting works
        {
            sort(x.begin(),x.end());
        }
        
        for(int i=0;i<n;i++)
        {
            if(merged[i].size() != 0)
            {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto x:merged[i])
                    temp.push_back(x);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};







