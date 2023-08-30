class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        string ans = "";
        
        for(auto x:s)
        {
            if(x == '*')
            {
                if(!ans.empty())
                    ans.pop_back();
            }
            else {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};