class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> count(26,0);
        unordered_map<int,int> m;
        int ans = 0;
        
        for(auto x:s)
            count[x-'a']++;
        // for(int i=0;i<26;i++)
        // {
        //     cout<<(char)(i+'a')<<" "<<count[i]<<endl;
        // }
        cout<<endl;
        for(int i=0;i<26;i++)
        {
            if(count[i] != 0)
                m[count[i]]++;
        }
        
        // for(auto x:m)
        //     cout<<x.first<<" "<<x.second<<endl;
        
        for(int i=0;i<n;i++)
        {
            int cnt = count[s[i]-'a'];
            while(m[cnt] > 1)
            {
                m[cnt]--;
                ans++;
                // cout<<s[i]<<" "<<i<<" "<<endl;
                count[s[i]-'a']--;
                cnt--;
                if(cnt == 0) break;
                m[cnt]++;
            }
        }
        
        return ans;
    }
};