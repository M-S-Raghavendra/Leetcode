class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = ""; 
        while(columnNumber)
        {
            int i = (columnNumber%26);
            char c;
            if(i == 0) 
            {
                c = 'Z';
                columnNumber -= 1;
            }
            else c = i + 'A' - 1;
            ans += c;
            columnNumber /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};