//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   bool checkCycle(vector<int> adj[], int v, vector<bool>& vis, vector<bool>& dfsVis, int node)
//   {
//       vis[node] = true;
//       dfsVis[node] = true;
      
//       for(auto neighbour : adj[node])
//       {
//           if(!vis[neighbour] and checkCycle(adj,v,vis,dfsVis,neighbour))
//                 return true;
//           else if(dfsVis[neighbour])
//             return true;
//       }
      
//       dfsVis[node] = false;
//       return false;
//   }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        queue<int> q;
        int indegree[V] = {0};
        // vector<bool> dfsVis(V,false);
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt++;
            
            for(auto x:adj[u])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        
        if(cnt == V)
            return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends