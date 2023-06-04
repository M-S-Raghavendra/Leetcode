class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(auto x:wordList)
            s.insert(x);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            string word = u.first;
            int num = u.second;
            
            if(word == endWord)
                return num;
            
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(int j=0;j<26;j++)
                {
                    char c = j + 'a';
                    word[i] = c;
                    // cout<<word<<" ";

                    if(s.find(word) != s.end())
                    {
                        q.push({word,num+1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};