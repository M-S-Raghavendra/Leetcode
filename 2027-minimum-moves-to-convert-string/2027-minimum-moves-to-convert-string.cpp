class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i=0;i<n-2;i++)
        {
            if(s[i] == 'O')
                continue;
            if(s[i] == 'X' or s[i+1] == 'X' or s[i+2] == 'X')
            {
                ans++;
                s[i] = s[i+1] = s[i+2] = 'O';
            }
        }
        
        if(s[n-3] == 'X' or s[n-2] == 'X' or s[n-1] == 'X')
        {
            ans++;
        }
        
        return ans;
    }
};