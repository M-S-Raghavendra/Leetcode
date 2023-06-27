class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0;
        int n = s.size();
        unordered_map<char,int> m;
        
        while(j < n)
        {
            m[s[j]]++;
            int sz = m.size();
            ans = max(ans, sz);
            
            while(i <= j and m.size() < (j-i+1))
            {
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
        
        int sz = m.size();
        ans = max(ans, sz);
        
        return ans;
    }
};