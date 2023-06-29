class Solution {
public:
    bool isMatching(char open, char close)
    {
        if((open == '(' and close == ')') or (open == '{' and close == '}') or (open == '[' and close == ']'))
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> stack;
        
        for(auto x:s)
        {
            char ch = x;
            
            if(x == '(' or x == '{' or x == '[')
                stack.push(x);
            else {
                if(stack.empty())
                    return false;
                if(isMatching(stack.top(),x))
                    stack.pop();
                else
                    return false;
            }
        }
        
        if(stack.empty())
            return true;
        else return false;
    }
};
