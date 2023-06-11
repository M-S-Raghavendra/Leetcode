class Solution {
public:
    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }
    
    bool checkConsec(string &s1, string &s2)
    {
        if(s1.size() != s2.size()+1)
            return false;
        int i = 0, j = 0;
        
        while(i < s1.size())
        {
            if(j < s2.size() and s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else 
                i++;
        }
        
        if(i == s1.size() and j == s2.size())
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        int maxi = 1;
        vector<int> dp(n,1);
        
        for(int i=-0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkConsec(words[i],words[prev]) and dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};