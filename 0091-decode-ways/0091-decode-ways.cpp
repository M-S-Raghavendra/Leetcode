class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }
    
    int f(int i, string &s, vector<int> &dp)
    {
        if(i == s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        string temp = "";
        temp += s[i];
        int one = f(i+1,s,dp);
        int two = 0;
        
        if(i+1 < s.size())
        {
            temp += s[i+1];
            if(stoi(temp) <= 26)
                two = f(i+2,s,dp);
        }
        
        return dp[i] = one + two;
    }
};