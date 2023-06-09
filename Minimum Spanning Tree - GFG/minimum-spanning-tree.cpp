//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    vector<int> size, par;
public:
    DisjointSet(int n) {
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
            par[i] = i;
    }
    
    int findUPar(int u) {
        if(par[u] == u)
            return u;
        return par[u] = findUPar(par[u]);
    }
    
    void unionBySize(int u, int v) {
        int upu = findUPar(u);
        int upv = findUPar(v);
        if(upu == upv)
            return;
        if(size[upu] < size[upv]) {
            par[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            par[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // // Prim's Algorithm
        // typedef pair<int,int> pp;
        // int sum = 0;
        // priority_queue<pp,vector<pp>,greater<pp>> pq;
        // pq.push({0,0});
        // vector<int> included(V,0);
        
        // while(!pq.empty())
        // {
        //     auto it = pq.top();
        //     pq.pop();
        //     int edgeW = it.first;
        //     int node = it.second;
            
        //     if(included[node])
        //         continue;
            
        //     included[node] = 1;
        //     sum += edgeW;
            
        //     for(auto x:adj[node])
        //     {
        //         int adjNode = x[0];
        //         int adjEdgeW = x[1];
                
        //         if(!included[adjNode])
        //         {
        //             pq.push({adjEdgeW,adjNode});
        //         }
        //     }
        // }
        
        // return sum;
        
        // Kruskal's Algorithm
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(y:adj[i])
            {
                edges.push_back({y[1],{i,y[0]}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(V);
        int sum = 0;
        for(auto x:edges)
        {
            int w = x.first;
            int node = x.second.first;
            int adjNode = x.second.second;
            
            if(ds.findUPar(node) != ds.findUPar(adjNode))
            {
                sum += w;
                ds.unionBySize(node,adjNode);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends