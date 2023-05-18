class Solution {
private:
    bool isVowel(char c)
    {
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U')
            return true;
        return false;
    }
    
public:
    string reverseVowels(string s) {
        stack<char> stk;
        for(auto x:s)
            if(isVowel(x))
                stk.push(x);
        
        for(int i=0;i<s.length();i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = stk.top();
                stk.pop();
            }
        }
        
        return s;
    }
};