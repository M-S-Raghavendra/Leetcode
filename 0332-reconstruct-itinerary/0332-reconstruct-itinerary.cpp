class Solution {
public:
    unordered_map<string,multiset<string>> adj;
    unordered_map<string,int> vis;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for(auto x:tickets)
        {
            adj[x[0]].insert(x[1]);
        }
        
        vector<string> ans;
        string start = "JFK";
        
        dfs(start,ans,n);
        
        return ans;
    }
    
    bool dfs(string s, vector<string> &ans, int n)
    {
        ans.push_back(s);
        int e = 0;
        for(auto x:vis) e += x.second;
        
        if(e == n)
            return true;
        
//         for(auto x:ans)
//                 cout<<x<<" ";
//         cout<<endl;
        
        for(auto x:adj[s])
        {
            string temp = s + "_" + x;
            if(vis[temp] != adj[s].count(x))
            {
                vis[temp]++;
                if(dfs(x,ans,n))
                    return true;
                vis[temp]--;
                if(vis[temp] == 0) vis.erase(temp);
            }
        }
        ans.pop_back();
        
        return false;
    }
};