class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 1;
        sort(pairs.begin(),pairs.end(),comp);
        int prev = 0;
        int n = pairs.size();
        
        for(int i=1;i<n;i++)        
        {
            if(pairs[i][0] > pairs[prev][1])
            {
                prev = i;
                ans++;
            }
        }
        return ans;
    }
};