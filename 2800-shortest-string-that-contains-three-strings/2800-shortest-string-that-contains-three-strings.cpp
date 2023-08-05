class Solution {
public:
    string minimumString(string a, string b, string c) {        
        string ans;
        
        ans = f(a,b,c);
        // cout<<ans<<endl;
        ans = minimum(ans,f(a,c,b));
        // cout<<ans<<endl;
        ans = minimum(ans,f(b,a,c));
        // cout<<ans<<endl;
        ans = minimum(ans,f(b,c,a));
        // cout<<ans<<endl;
        ans = minimum(ans,f(c,a,b));
        // cout<<ans<<endl;
        ans = minimum(ans,f(c,b,a));
        // cout<<ans<<endl;
        
        return ans;
    }
    
    string f(string &a, string &b, string &c)
    {
        string ans = a;
        string temp = contains(ans,b);
        // cout<<temp;
        if(temp != "")
            ans = temp;
        else
            ans += merge(ans,b);
        
        temp = contains(ans,c);
        if(temp != "")
            ans = temp;
        else
            ans += merge(ans,c);
        
        return ans;
    }
    
    string contains(string &a, string &b)
    {
        if(a.find(b) != string::npos)
            return a;
        if(b.find(a) != string::npos)
            return b;
        return "";
    }
    
    string merge(string &a, string &b)
    {
        int i = a.size()-1;
        int j = 0;
        int mxComLen = 0;
        string prefix = "";
        
        while(i>=0 and j<b.size())
        {
            string suffix = a.substr(i);
            prefix += b[j];
            // cout<<suffix<<" "<<prefix<<endl;
            
            if(suffix == prefix)
                mxComLen = prefix.size();
            i--;
            j++;
        }
        // cout<<mxComLen<<endl;
        
        return b.substr(mxComLen);
    }
    
    string minimum(string a, string b)
    {
        if(a.size() == b.size())
        {
            if(a < b)
                return a;
            return b;
        }
        
        if(a.size() < b.size())
            return a;
        return b;
    }
};