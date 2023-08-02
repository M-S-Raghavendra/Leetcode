class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string sen = "";
        unordered_set<string> set;
        for(auto x:wordDict)
            set.insert(x);
        f(0,s,set,sen,ans);
        return ans;
    }
    
    void f(int i, string &s, unordered_set<string> &set, string &sen, vector<string> &ans)
    {
        if(i == s.size())
        {
            sen.pop_back();
            ans.push_back(sen);
            sen += " ";
            return;
        }
        
        string temp = "";
        for(int j=i;j<s.size();j++)
        {
            temp += s[j];
            if(set.find(temp) != set.end())
            {
                sen += (temp + " ");
                f(j+1,s,set,sen,ans);
                for(auto x:temp)
                    sen.pop_back();
                sen.pop_back();
            }
        }
    }
};