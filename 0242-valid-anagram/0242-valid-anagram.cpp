class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n != m) return false;
        
        int hash[26] = {0};
        for(int i=0;i<n;i++)
        {
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            if(hash[i] != 0)
                return false;
        }
        return true;
    }
};