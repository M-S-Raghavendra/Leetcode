class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        typedef array<int,26> f;
        map<f,vector<string>> m;
        
        int n = strs.size();
        
        for(auto x:strs)
        {
            array<int,26> a;
            a.fill(0);
            for(auto y:x)
            {
                a[y-'a']++;
            }
            
            if(m.find(a) != m.end())
                m[a].push_back(x);
            else
                m.insert({a,{x}});
        }
        
        vector<vector<string>> ans;
        
        for(auto x:m)
            ans.push_back(x.second);
        
        return ans;
    }
};