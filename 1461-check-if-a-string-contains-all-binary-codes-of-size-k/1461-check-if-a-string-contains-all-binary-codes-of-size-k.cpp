class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;
        
        unordered_set<string> set;
        int n = s.size();
        string sub = "";
        
        for(int i=0;i<n;i++)
        {
            sub += s[i];
            if(i >= k)
                sub.erase(sub.begin());
            if(i >= k-1)
            {
                if(!set.count(sub))
                    set.insert(sub);
            }
        }
        
        return (set.size() == (1<<k));
    }
};