class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> s;     
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and temp[s.top()] <= temp[i])
                s.pop();
            if(!s.empty())
            {
                int ind = s.top();
                ans[i] = (ind-i);
            }
            s.push(i);  //Push "index" instead of element
        }
        
        return ans;
    }
};