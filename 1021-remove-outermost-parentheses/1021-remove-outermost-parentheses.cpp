class Solution {
public:
    string removeOuterParentheses(string s) {
        int i = 0, j = 0;
        int n = s.length();
        stack<char> stack;
        string ans = "";
        
        while(i < n and j < n)
        {
            do
            {
                if(s[j] == '(')
                    stack.push(s[j]);
                else
                    stack.pop();
                j++;
            }while(j < n and !stack.empty());
            
            j--;
            
            for(int k=i+1;k<j;k++)
                ans += s[k];
            
            j++;
            i = j;
        }
        
        return ans;
    }
};