class Solution {
public:
    unordered_map<string,vector<int>> dp;
    
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        
        return f(0,n-1,expression);
    }
    
    vector<int> f(int i, int j, string &exp)
    {
        int n = exp.size();
        if(i > j)
            return {};
        if(i == j or i+1 == j)
            return {stoi(exp.substr(i,j-i+1))};
        
        string temp = to_string(i);
        temp += '_';
        temp += to_string(j);
        if(dp.find(temp) != dp.end()) return dp[temp];
        
        int l = isdigit(exp[i+1]) ? i+2 : i+1;
        int r = isdigit(exp[j-1]) ? j-1 : j;
        
        vector<int> ans;
        for(int k=l;k<r;k+=2)
        {
            vector<int> left = f(i,k-1,exp);
            vector<int> right = f(k+1,j,exp);
            
            for(auto x:left)
            {
                for(auto y:right)
                {
                    if(exp[k] == '+')
                        ans.push_back(x+y);
                    else if(exp[k] == '-')
                        ans.push_back(x-y);
                    else if(exp[k] == '*')
                        ans.push_back(x*y);
                }
            }
            if(k+2 < n and isdigit(exp[k+2]))
                k++;
        }
        
        return dp[temp] = ans;
    }
};