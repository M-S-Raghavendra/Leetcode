class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = ""; 
        int n = columnNumber;
        
        while(n)
        {
            n--;    //To convert 1->A to 0->A
            char c = (n%26) + 'A';
            ans = c + ans;
            n /= 26;
            
            // int i = (columnNumber%26);
            // char c;
            // if(i == 0) 
            // {
            //     c = 'Z';
            //     columnNumber -= 1;
            // }
            // else c = i + 'A' - 1;
            // ans += c;
            // columnNumber /= 26;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};