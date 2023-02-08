class Solution {
public:
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
        unordered_map<char,int> m1;
        for(auto x:s1)
            m1[x]++;
        
        for(int i=0;i<=s2.length()-s1.length();i++)
        {
            bool notSub = false;
            unordered_map<char,int> m2;
            
            for(int j=0;j<s1.length();j++)
            {
                m2[s2[i+j]]++;
            }
            
            if(m1.size() != m2.size())
                continue;
            
            for(auto x:m1)
            {
                if(x.second != m2[x.first])
                {
                    notSub = true;
                    break;
                }
            }
            
            if(notSub == false)
                return true;
        }
        
        return false;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        return solve(s1,s2);
    }
};