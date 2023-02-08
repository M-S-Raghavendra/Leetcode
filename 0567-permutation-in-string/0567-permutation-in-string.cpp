class Solution {
public:
    bool check(unordered_map<char,int> &m1, unordered_map<char,int> &m2)
    {
        if(m1.size() != m2.size())
            return false;
        
        for(auto x:m1)
        {
            if(x.second != m2[x.first])
                return false;
        }
        return true;
        }
    
    bool solve(string &s1, string &s2)
    {
        //Approach 1
//         sort(s1.begin(),s1.end());
        
//         for(int i=0;i<=s2.length()-s1.length();i++)
//         {
//             string sub = s2.substr(i,s1.length());
//             sort(sub.begin(),sub.end());
//             if(s1 == sub)
//                 return true;
//         }
        
//         return false;
        
        //Approach 2
        unordered_map<char,int> m1,m2;
        for(auto x:s1)
            m1[x]++;
        for(int i=0;i<s1.length();i++)
            m2[s2[i]]++;
        if(check(m1,m2)) return true;
        
        int n = s1.length();
        for(int i=n;i<=s2.length();i++)
        {            
            m2[s2[i]]++;
            if(--m2[s2[i-n]] == 0)
            {
                m2.erase(s2[i-n]);
            }
            if(check(m1,m2)) return true;
        }
        
        return false;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        return solve(s1,s2);
    }
};