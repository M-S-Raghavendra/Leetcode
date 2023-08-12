class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        return (1.0 * a.first / a.second) < (1.0 * b.first / b.second);
    }
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({dist[i],speed[i]});
        
        sort(v.begin(),v.end(),comp);
        // for(auto x:v)
        //     cout<<x.first<<" "<<x.second<<endl;
        
        int ans = 0;
        long long time = 0;
        
        for(int i=0;i<v.size();i++)
        {
            long long d = v[i].first;
            long long sp = v[i].second;
            
            if(d - (time * sp) <= 0)
                break;
            ans++;
            time++;
        }
        
        return ans;
    }
};