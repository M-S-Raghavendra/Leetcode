class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            vector<int> mxfreq(26,0), mnfreq(26,INT_MAX);
            for(int j=i;j<n;j++)
            {
                mxfreq[s[j]-'a']++;
                if(mnfreq[s[j]-'a'] == INT_MAX)
                    mnfreq[s[j]-'a'] = 1;
                else
                    mnfreq[s[j]-'a']++;
                int mx = *max_element(mxfreq.begin(),mxfreq.end());
                int mn = *min_element(mnfreq.begin(),mnfreq.end());
                ans += (mx - mn);
                // cout<<mx<<" "<<mn<<endl;
            }
            // for(auto x:freq)
            //     cout<<x<<" ";
            // cout<<endl;
        }
        
        return ans;
    }
};