class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int,int>> s;
        vector<int> deg(n);
        
        for(auto x:roads)
        {
            deg[x[0]]++;
            deg[x[1]]++;
            s.insert({x[0],x[1]});
        }
        
        for(auto x:deg)
            cout<<x<<" ";
        
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cur = deg[i] + deg[j];
                if(s.find({i,j}) != s.end() or s.find({j,i}) != s.end())
                    cur--;
                maxi = max(maxi,cur);
            }
        }
        
        return maxi;
    }
};