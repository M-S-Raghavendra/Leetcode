class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        for(auto x:s)
            hash[x-'a']++;
        for(auto x:t)
            hash[x-'a']--;
        for(int i=0;i<26;i++)
        {
            if(hash[i] != 0)
                return false;
        }
        return true;
    }
};