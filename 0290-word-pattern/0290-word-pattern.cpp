class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_set<string> set;
        vector<string> words;
        
        string temp;
        stringstream ss(s);
        
        while(ss >> temp)
        {
            words.push_back(temp);
        }
        
        if(pattern.size() != words.size())
            return false;
        
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i]) != m.end())
            {
                if(m[pattern[i]] != words[i])
                    return false;
            }
            else if(set.find(words[i]) != set.end())
                return false;
            else {
                m.insert({pattern[i],words[i]});
                set.insert(words[i]);
            }
        }
        
        return true;
    }
};