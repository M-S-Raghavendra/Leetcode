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
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int mini = INT_MAX;
            int cuts;
            for(int ind=i;ind<s.size();ind++)
            {
                if(isPalindrome(i,ind,s))
                {
                    cuts = 1 + dp[ind+1];
                    mini = min(mini,cuts);
                }
            }

            dp[i] = mini;
        }

        return dp[0] - 1;  // it is cutting at end also, aab --> aa|b| , so "-1"
    }
};