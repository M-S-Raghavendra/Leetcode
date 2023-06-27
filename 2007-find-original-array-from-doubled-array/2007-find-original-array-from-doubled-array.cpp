class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2 == 1)
            return {};
        
        sort(changed.begin(),changed.end());
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto x:changed)
            m[x]++;
        unordered_set<int> s;
        
        for(int i=0;i<n;i++)
        {
            if(s.find(changed[i]) != s.end())
            {
                s.erase(changed[i]);
                continue;
            }
            if(changed[i] == 0 and m.find(changed[i]) != m.end())
            {
                if(m[changed[i]] < 2)
                    return {};
            }
            if(m.find(changed[i]) != m.end() and (m.find(2*changed[i])) != m.end())
            {
                ans.push_back(changed[i]);
                
                m[changed[i]]--;
                if(m[changed[i]] == 0)
                    m.erase(changed[i]);
                m[2*changed[i]]--;
                s.insert(2*changed[i]);
                if(m[2*changed[i]] == 0)
                    m.erase(2*changed[i]);
            }
            
            if(ans.size() == n/2)
                return ans;
        }
        
        if(ans.size() != n/2)
            return {};
        
        return ans;
    }
};