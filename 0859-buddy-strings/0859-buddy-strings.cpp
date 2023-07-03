class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        
        if(n != m) return false;
        int ind1 = -1, ind2 = -1;
        int cnt = 0;
        vector<int> count(26);
        
        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
            if(s[i] != goal[i])
            {
                if(ind1 == -1) ind1 = i;
                else ind2 = i;
                cnt++;
            }
        }
        
        if(cnt > 2) return false;
        if(cnt == 1) return false;
        if(cnt == 0)
        {
            for(auto x:count)
                if(x > 1)
                    return true;
            return false;
        }
        
        swap(s[ind1],s[ind2]);
        if(s == goal)
            return true;
        else return false;
    }
};