class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        int n = chars.size();
        
        while(i<n and j<n)
        {
            int start = j;
            while(j<n and chars[j] == chars[start])
                j++;
            int cnt = j-start;
            
            chars[i] = chars[start];
            
            if(cnt == 1)
                i++;
            else {
                if(cnt < 10)
                {
                    chars[i+1] = (char)(cnt + '0');
                    i += 2;
                }
                else {
                    vector<char> count;
                    numToChar(cnt,count);
                    for(int k=0;k<count.size();k++)
                    {
                        chars[i+1+k] = count[k];
                    }
                    
                    i = i+1+count.size();
                }
            }
        }
        
        return i;
    }
    
    void numToChar(int cnt, vector<char>& c)
    {
        string s = to_string(cnt);
        for(auto x:s)
            c.push_back(x);
    }
};