class WordDictionary {
private:
    unordered_set<string> s;
    
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        int dots = 0;
        int i = -1, j = -1;
        int n = word.size();
        
        for(int k=0;k<n;k++)
            if(word[k] == '.')
            {
                dots++;
                if(i == -1)
                    i = k;
                else
                    j = k;
            }
        
        if(dots == 0)
            return s.count(word);
        else if(dots == 1) {
            for(int k=0;k<26;k++)
            {
                word[i] = k + 'a';
                if(s.count(word))
                    return true;
            }
            return false;
        }
        else if(dots == 2) {
            for(int l=0;l<26;l++)
            {
                word[i] = l+'a';
                for(int m=0;m<26;m++)
                {
                    word[j] = m+'a';
                    if(s.count(word))
                        return true;
                }
            }
            return false;
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */