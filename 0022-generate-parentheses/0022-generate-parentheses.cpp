class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> ans;
        string comb = "";
        f(n,comb,ans,open,close);
        return ans;
    }
    
    void f(int n, string &s, vector<string> &ans, int open, int close)
    {
        if(close == n)
        {
            ans.push_back(s);
            return ;
        }
        
        if(open < n)
        {
            s += '(';
            f(n,s,ans,open+1,close);
            s.pop_back();
        }
        if(open > close)
        {
            s += ')';
            f(n,s,ans,open,close+1);
            s.pop_back();
        }
        
    }
};