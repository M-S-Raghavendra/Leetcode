class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        priority_queue<pair<int,char>> pq;
        
        for(auto x:s)
            count[x-'a']++;
        for(int i=0;i<26;i++)
            pq.push({count[i],i+'a'});
            
        int mxcnt = ceil(1.0 * s.size() / 2);
        
        for(int i=0;i<26;i++)
            if(count[i] > mxcnt)
                return "";
        
        string ans = "";
        
        while(ans.size() < s.size())
        {
            if(!ans.empty() and pq.top().second == ans.back())
            {
                auto t = pq.top();
                pq.pop();
                if(pq.empty())
                    return "";
                auto p = pq.top(); pq.pop();
                ans += p.second;
                if(p.first > 1)
                    pq.push({p.first-1,p.second});
                pq.push(t);
            }
            else {
                auto p = pq.top();
                ans += p.second;
                pq.pop();
                if(p.first > 1)
                    pq.push({p.first-1,p.second});
            }
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};