class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int,int>> s;
        vector<int> deg(n);
        
        for(auto &x:roads)
        {
            deg[x[0]]++;
            deg[x[1]]++;
            s.insert({x[0],x[1]});
        }
        
        int maxi = INT_MIN;
        int cur;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cur = deg[i] + deg[j];
                if(s.count({i,j}) or s.count({j,i}))
                    cur--;
                maxi = max(maxi,cur);
            }
        }
        
        return maxi;
    }
};