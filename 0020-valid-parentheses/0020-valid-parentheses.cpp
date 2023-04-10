class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        
        for(int i=0;i<s.length();i++)
        {
            int ch = s[i];
            
            if(ch == '(' or ch=='{' or ch == '[')
                c.push(ch);
            else{
                if(c.empty())
                    return false;
                int t = c.top();
                
                if((ch==')' and t == '(') or (ch=='}' and t == '{') or (ch==']' and t=='['))
                    c.pop();
                else
                    return false;
            }
        }
        
        return c.empty();
    }
};