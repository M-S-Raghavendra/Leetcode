class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int l = words.size();
        int c = words[0].size();
        vector<int> ans;
        unordered_map<string,int> w;
        for(int i=0;i<l;i++)
            w[words[i]]++;
        int windowSize = c*l;
        int j, cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            j = i + windowSize;
            if(j > n) break;
            cnt = 0;
            
            if(check(s,i,j,l,c,w))
                ans.push_back(i);
        }
        
        return ans;
    }
    
    bool check(string &s, int i, int j, int l, int c, unordered_map<string,int> w)
    {
        string sub;
        for(int k=0;k<l;k++)
        {
            sub = s.substr(i+c*k,c);
            if(--w[sub] == -1)
                return  false;
        }
        return true;
    }
};