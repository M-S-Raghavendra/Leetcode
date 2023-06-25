class Solution {
public:
    string letters(int n)
    {
        switch(n)
        {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
            default: return "";
        }
        return "";
    }
    
    void f(int i, string &digits, string &s, vector<string> &ans)
    {
        if(i == digits.size())
        {
            ans.push_back(s);
            return ;
        }
        
        string map = letters(digits[i]-'0');
        
        for(int j=0;j<map.size();j++)
        {
            s.push_back(map[j]);
            f(i+1,digits,s,ans);
            s.pop_back();
        }
    }
        
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        
        if(n == 0)
            return {};
        
        vector<string> ans;
        string s = "";
        
        f(0,digits,s,ans);
        return ans;
    }
};