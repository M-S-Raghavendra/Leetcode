class Solution {
public:
    void f(int i, vector<int> &c, vector<int> &dist, int &ans)
    {
        if(i == c.size())
        {
            int mx = *max_element(dist.begin(),dist.end());
            ans = min(ans, mx);
            return;
        }
        
        for(int j=0;j<dist.size();j++)
        {
            dist[j] += c[i];
            f(i+1,c,dist,ans);
            dist[j] -= c[i];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k,0);
        int ans = INT_MAX;
        f(0,cookies,dist,ans);
        return ans;
    }
};