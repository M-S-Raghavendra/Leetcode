class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++)
            if(!color[i])
                if(!bfs(i,graph,color))
                    return false;
        
        return true;
    }
    
    int bfs(int s, vector<vector<int>>& graph, vector<int> &color)
    {
        queue<int> q;
        q.push(s);
        color[s] = 1;
        
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            for(auto x:graph[i])
            {
                if(!color[x])
                {
                    color[x] = -color[i];
                    q.push(x);
                }
                else if(color[x] == color[i])
                    return false;
            }
        }
        
        return true;
    }
};