//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        vector<int> dist(N,1e9);
        vector<int> vis(N,0);
        queue<pair<int,int>> q;
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
            
        q.push({src,0});
        vis[src] = 1;
        dist[src] = 0;
        
        while(!q.empty())
        {
            pair<int,int> u = q.front();
            q.pop();
            
            int v = u.first;
            int w = u.second;
            
            dist[v] = w;
            
            for(auto x:adj[v])
            {
                if(!vis[x])
                {
                    vis[x] = 1;
                    q.push({x,w+1});
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i] == 1e9)
                dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends