class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<char> set;
        
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i]) != m.end())
            {
                if(m[s[i]] != t[i])
                    return false;
            }
            else {
                if(set.find(t[i]) != set.end())
                    return false;
                m[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        
        return true;
    }
};