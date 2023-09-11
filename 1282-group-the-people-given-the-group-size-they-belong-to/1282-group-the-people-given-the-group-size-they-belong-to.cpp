class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> vis(n);
        int visCnt = 0;
        vector<vector<int>> ans;
        
        while(visCnt < n)
        {
            vector<int> v;
            int i = 0;
            while(i<n and vis[i])
                i++;
            if(i == n) break;
            int sz = groupSizes[i];
            while(v.size() < sz)
            {
                if(groupSizes[i] == sz and !vis[i])
                {
                    v.push_back(i);
                    vis[i] = 1;
                    visCnt++;
                }
                i++;
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};