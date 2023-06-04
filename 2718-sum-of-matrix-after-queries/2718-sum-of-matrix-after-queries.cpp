class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        bool seen[2][10001] = {};
        long long rem[2] = {n,n};
        
        for(int i=queries.size()-1;i>=0;i--)
        {
            int type = queries[i][0];
            int ind = queries[i][1];
            int val = queries[i][2];
            
            if(!seen[type][ind]) {
                seen[type][ind] = true;
                ans += val * rem[!type];
                rem[type]--;
            }
        }
        
        return ans;
    }
};