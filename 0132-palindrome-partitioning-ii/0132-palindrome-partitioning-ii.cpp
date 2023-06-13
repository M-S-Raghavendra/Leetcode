class Solution {
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    int f(int i, string &s, vector<int> &dp)
    {
        if(i == s.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int mini = INT_MAX;
        for(int ind=i;ind<s.size();ind++)
        {
            if(isPalindrome(i,ind,s))
            {
                int cuts = 1 + f(ind+1,s,dp);
                mini = min(mini,cuts);
            }
        }
        
        return dp[i] = mini;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        
        return f(0,s,dp) - 1;  // it is cutting at end also, aab --> aa|b| , so "-1"
    }
};