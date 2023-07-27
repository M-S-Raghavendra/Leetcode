class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int n = s.size();
        int cnt = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] != '-')
            {
                if(isalpha(s[i]))
                    ans += toupper(s[i]);
                else
                    ans += s[i];
                cnt++;
            }
            if(cnt == k)
            {
                ans += '-';
                cnt = 0;
            }
        }
        if(!ans.empty() and ans.back() == '-')
            ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};