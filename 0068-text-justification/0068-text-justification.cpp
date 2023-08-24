class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        string temp = "";
        int i = 0;
        vector<int> count;
        
        while(i < n) 
        {
            temp = "";
            int cnt = 0;
            for(;i<n;i++)
            {
                if(words[i].size() + temp.size() <= maxWidth)
                {
                    temp += words[i];
                    temp += " ";
                    cnt++;
                }
                else break;
            }
            temp.pop_back(), cnt--;
            ans.push_back(temp);
            count.push_back(cnt);
        }
        
        int rem, mod, sp;
        string stuff;
        int m = ans.size();
        
        for(int i=0;i<m-1;i++)
        {
            if(count[i] == 0) {
                rem = maxWidth - ans[i].size();
                string tt = "";
                while(rem--)
                    tt += ' ';
                ans[i] += tt;
                continue;
            }
            rem = maxWidth - ans[i].size();
            mod = rem % count[i];
            sp = rem / count[i];
            
            // cout<<ans[i]<<" "<<count[i]<<" "<<rem<<" "<<mod<<" "<<sp<<endl;
            
            stuff = "";
            for(int k=0;k<sp;k++)
                stuff += ' ';
            
            // cout<<stuff.size()<<" "<<sp<<endl;
            string c;
            string temp = "";
            
            for(int j=0;j<ans[i].size();j++)
            {
                temp += ans[i][j];
                if(ans[i][j] != ' ') continue;
                if(mod)
                    c = " ", mod--;
                else
                    c = ""; 
                temp += (stuff + c);
            }
            ans[i] = temp;
        }
        
        stuff = "";
        int remlast = maxWidth - ans[m-1].size();
        while(remlast--)
            stuff += ' ';
        ans[m-1] += stuff;
        
        return ans;
    }
};