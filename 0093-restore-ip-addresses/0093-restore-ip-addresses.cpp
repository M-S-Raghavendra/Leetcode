class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string str = "";
        f(0,s,str,ans);
        return ans;
    }
    
    void f(int i, string s, string &str, vector<string> &ans)
    {
        int n = s.size();
        
        if(i == n)
        {
            int dots = 0;
            str.pop_back();
            for(auto x:str)
                if(x == '.')
                    dots++;
            if(dots == 3)
                ans.push_back(str);
            str.push_back('.');
            return;
        }
        
        string temp = "";
        for(int j=i;j<min(n,i+3);j++)
        {
            temp += s[j];
            int sub = stoi(temp);
            if(j-i+1 > 1 and temp[0] == '0')
                break;
            if(sub > 255)
                break;
            
            str += temp;
            str += '.';
            f(j+1,s,str,ans);
            str.pop_back();
            for(int k=0;k<temp.size();k++)
                str.pop_back();
        }
    }
};