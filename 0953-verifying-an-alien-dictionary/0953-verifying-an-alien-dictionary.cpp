class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        
        unordered_map<char,int> m;
        for(int i=0;i<order.size();i++)
            m[order[i]] = i;
        
        for(int i=0;i<n-1;i++)
        {
            string a = words[i];
            string b = words[i+1];
                        
            int p=0;
            int cnt = 0;
            while(p<a.size() and p<b.size())
            {
                if(a[p] != b[p])
                {
                    cnt++;
                    if(m[a[p]] > m[b[p]])
                        return false;
                    else
                        break;
                }
                p++;
            }
            if((a.size() > b.size()) and cnt == 0)
                return false;
        }
        
        return true;
    }
};