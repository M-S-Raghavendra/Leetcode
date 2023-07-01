class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int temp;
        int ans = 0;
        
        int count[26] = {0};
        for(auto x:s)
            count[x-'A']++;
        int mx = *max_element(count,count+26);
        if(n-mx <= k)
            return n;
        
        while(i < n and j < n)
        {
            temp = k;
            while(j < n and (s[j] == s[i] or temp > 0))
            {
                if(s[j] != s[i]) temp--;
                j++;
            }
            
            ans = max(ans,(j-i));
            i++;
            while(i < n and s[i] == s[i-1])
                i++;
            j = i;
        }
        
        i = n-1, j = n-1;
        while(i >= 0 and j >= 0)
        {
            temp = k;
            while(j >= 0 and (s[j] == s[i] or temp > 0))
            {
                if(s[j] != s[i]) temp--;
                j--;
            }
            
            ans = max(ans,(i-j));
            i--;
            while(i >= 0 and s[i] == s[i+1])
                i--;
            j = i;
        }
        
        return ans;
    }
};