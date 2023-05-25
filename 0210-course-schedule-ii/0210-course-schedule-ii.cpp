class Solution {
private:
    bool dfs(int src, vector<vector<int>> &adj, stack<int> &s, vector<bool> &vis, vector<bool>& dfsvis)
    {
        vis[src] = true;
        dfsvis[src] = true;
        
        for(auto nei:adj[src])
        {
            if(!vis[nei])
            {
                if(!dfs(nei,adj,s,vis,dfsvis))
                   return false;
            }
            else if(dfsvis[nei])
                return false;
        }
        
        cout<<src<<" ";
        s.push(src);
        dfsvis[src] = false;
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses), dfsvis(numCourses);
        stack<int> s;
        vector<int> ans;
        
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,adj,s,vis,dfsvis))
                    return {};
            }
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};