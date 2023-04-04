class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int i = 0;
        int cnt = 0;
        
        while(i < n)
        {
            unordered_set<char> pre;
            while(i < n and pre.find(s[i]) == pre.end())
            {
                pre.insert(s[i]);
                i++;
            }
            cnt++;
        }
        
        return cnt;
    }
};