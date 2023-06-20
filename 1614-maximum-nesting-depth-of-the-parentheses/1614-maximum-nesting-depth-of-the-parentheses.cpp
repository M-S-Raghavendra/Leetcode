class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int nd = 0;
        
        for(auto x:s)
        {
            if(x == '(')
            {
                stk.push(x);
                int sz = stk.size();
                nd = max(nd, sz);
            }
            else if(x == ')')
            {
                stk.pop();
            }
        }
        
        return nd;
    }
};