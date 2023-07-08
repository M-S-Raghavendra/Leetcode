class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int i = 0, j;
        int ans = 0;
        
        for(j=0;j<s.size();j++)
        {
            m[s[j]]++;
            while(m.size() == 3)
            {
                ans += s.size() - j;
                m[s[i]]--;
                if(m[s[i]] == 0)
                     m.erase(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};