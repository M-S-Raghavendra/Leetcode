class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        vector<vector<string>> ans;
        vector<string> v;
        f(0,s,v,ans);
        return ans;
    }
    
    void f(int ind, string &s, vector<string> &v, vector<vector<string>> &ans)
    {
        if(ind == s.size())
        {
            ans.push_back(v);
            return ;
        }
        
        for(int i=ind;i<s.size();i++)
        {
            string t = s.substr(ind,i-ind+1);
            if(ispalindrome(t))
            {
                v.push_back(t);
                f(i+1,s,v,ans);
                v.pop_back();
            }
        } 
    }
    
    bool ispalindrome(string &str)
    {
        int s = 0, e = str.size()-1;
        while(s <= e)
        {
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }
};