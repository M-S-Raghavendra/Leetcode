//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int,int>>> adj(N);
         vector<int> topo;
         queue<int> q;
         vector<int> indegree(N,0);
         
         for(auto x:edges)
         {
             adj[x[0]].push_back({x[1],x[2]});
         }
         
         for(auto x:edges)
            indegree[x[1]]++;
        for(int i=0;i<N;i++)
            if(indegree[i] == 0)
                q.push(i);
                
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            
            for(auto x:adj[u])
            {
                indegree[x.first]--;
                if(indegree[x.first] == 0)
                    q.push(x.first);
            }
        }
        
        // for(auto x:topo)
        //     cout<<x<<" ";
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        
        for(int i=0;i<N;i++)
        {
            for(auto x:adj[topo[i]])
            {
                if(dist[x.first] > dist[topo[i]] + x.second)
                    dist[x.first] = dist[topo[i]] + x.second;
            }
        }
        
        for(int i=0;i<N;i++)
            if(dist[i] == 1e9)
                dist[i] = -1;
                
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends