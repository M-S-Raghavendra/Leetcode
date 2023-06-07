class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjM(n,vector<int>(n,1e9));
        for(auto x:edges)
        {
            adjM[x[0]][x[1]] = x[2];
            adjM[x[1]][x[0]] = x[2];
        }
        for(int i=0;i<n;i++)
            adjM[i][i] = 0;
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adjM[i][j] = min(adjM[i][j], adjM[i][k] + adjM[k][j]);
                }
            }
        }
        
        int ans = -1;
        int mncities = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int cur = 0;
            for(int j=0;j<n;j++)
            {
                if(adjM[i][j] <= distanceThreshold)
                    cur++;
            }
            if(cur <= mncities)
            {
                // cout<<mncities<<" "<<cur<<endl;
                mncities = cur;
                ans = i;
            }
        }
        
        return ans;
    }
};