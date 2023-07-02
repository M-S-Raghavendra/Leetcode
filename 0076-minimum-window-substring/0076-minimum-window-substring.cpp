class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(m > n) return "";
        
        unordered_map<char,int> m1,m2;
        for(auto x:t)
            m2[x]++;
        
        int i = 0, j = 0;
        string ans = "";
        int mnLen = INT_MAX;
        
        while(j <= n)
        {
            m1[s[j]]++;
            bool flag = true;
            for(auto x:m2)
            {
                if(m1[x.first] < x.second)
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                if(j-i+1 < mnLen)
                {
                    ans = s.substr(i,j-i+1);
                    mnLen = ans.size();
                }
                m1[s[i]]--;
                if(m1[s[i]] == 0) m1.erase(s[i]);
                i++;
                while(i <= j and (m2.find(s[i]) == m2.end() or m1[s[i]] > m2[s[i]]))
                {
                    m1[s[i]]--;
                    if(m1[s[i]] == 0) m1.erase(s[i]);
                    i++;
                }
                bool f = true;
                for(auto x:m2)
                {
                    if(m1[x.first] < x.second)
                    {
                        f = false;
                        break;
                    }
                }

                if(f and j-i < mnLen)
                {
                    ans = s.substr(i,j-i+1);
                    mnLen = ans.size();
                }
            }
            j++;
        }
        
//         bool f = true;
//         for(auto x:m2)
//         {
//             if(m1[x.first] < x.second)
//             {
//                 f = false;
//                 break;
//             }
//         }

//         if(f and j-i < mnLen)
//         {
//             ans = s.substr(i,j-i+1);
//             mnLen = ans.size();
//         }
        
        return ans;
    }
};