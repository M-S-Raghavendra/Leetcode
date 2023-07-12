class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int l, r;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            // ODD Palindromic substring CENTERED at i
            l = r = i;
            while(l >= 0 and r < n and s[l] == s[r])
            {
                ans++;
                l--, r++;
            }
            
            // EVEN Palindromic substring CENTERED at i adn i+1
            l = i, r = i+1;
            while(l >= 0 and r < n and s[l] == s[r])
            {
                ans++;
                l--, r++;
            }
        }
        
        return ans;
    }
};