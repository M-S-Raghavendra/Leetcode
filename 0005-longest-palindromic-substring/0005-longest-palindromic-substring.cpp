class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int mxLen = 0;
        int n = s.size();
        int l, r;
        int start, end;
        
        for(int i=0;i<n;i++)
        {
            // ODD length palindrome checking by EXPANDING from CENTER
            l = r = i;
            while(l >= 0 and r < n and s[l] == s[r])
            {
                if(r-l+1 > mxLen) {
                    mxLen = r-l+1;
                    start = l, end = r;
                }
                l--;
                r++;
            }
            
            // EVEN length palindrome checking by EXPANDING from CENTERS
            l = i, r = i+1;
            while(l >= 0 and r < n and s[l] == s[r])
            {
                if(r-l+1 > mxLen) {
                    mxLen = r-l+1;
                    start = l, end = r;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(start, mxLen);
    }
};