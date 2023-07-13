class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(n,-1);
        
        return f(0,s,dict,dp);
    }
    
    bool f(int i, string &s, unordered_set<string> &dict, vector<int> &dp)
    {
        if(i == s.size())
            return true;
        
        if(dp[i] != -1) return dp[i];
        
        string temp = "";
        for(int j=i;j<s.size();j++)
        {
            temp += s[j];
            if(dict.find(temp) != dict.end())
            {
                if(f(j+1,s,dict,dp))
                    return dp[i] = true;
            }
        }
        
        return dp[i] = false;
    }
};