class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        int s = 0, e = 0;
        string ans = "";
        
        while(s < n and e < n)
        {
            while(e < n and title[e] != ' ')
                e++;
            
            int l = e-s;
            
            if(l == 1 or l == 2)
            {
                string str = title.substr(s,l);
                ans += lower(str);
            }
            else {
                string str = title.substr(s+1,l-1);
                ans += toupper(title[s]);
                ans += lower(str);
            }
            ans += ' ';
            e++;
            s = e;
            // cout<<s<<" "<<e<<"\n";
        }
        ans.pop_back();
        return ans;
    }
    
    string lower(string s)
    {
        for(int i=0;i<s.length();i++)
            s[i] = tolower(s[i]);
        return s;
    }
    
    string upper(string s)
    {
        for(int i=0;i<s.length();i++)
            s[i] = toupper(s[i]);
        return s;
    }
};