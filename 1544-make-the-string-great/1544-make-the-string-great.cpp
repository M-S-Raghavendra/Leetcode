class Solution {
public:
    string makeGood(string s) {
        if(s.size() < 2)
            return s;
        
        string ans = "";
        stack<char> stk;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            if(!stk.empty() and check(stk.top(),s[i]))
            {
                stk.pop();
                cnt++;
            }
            if(cnt == 0)
                stk.push(s[i]);
        }
        
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    bool check(char a , char b)
    {
        return ((a+32 == b) or (a - 32 == b));
    }
};