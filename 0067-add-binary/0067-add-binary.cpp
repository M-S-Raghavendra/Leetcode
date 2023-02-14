class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.length();
        int bl = b.length();
        int i = al-1, j = bl-1;
        int carry = 0;
        string s = "";
        int x, y, sum;
        
        while(i>=0 and j>=0)
        {
            x = a[i]-'0';
            y = b[j]-'0';
            
            sum = (x + y + carry);
            carry = (sum > 1)?1:0;
            sum %= 2;
            s += sum + '0';
            
            i--;
            j--;
        }
        
        while(i>=0)
        {
            x = a[i]-'0';
            
            sum = (x + carry);
            carry = (sum > 1)?1:0;
            sum %= 2;
            s += sum + '0';
            i--;
        }
        
        while(j>=0)
        {
            y = b[j]-'0';
            
            sum = (y + carry);
            carry = (sum > 1)?1:0;
            sum %= 2;
            s += sum + '0';
            j--;
        }
        
        if(carry != 0)
            s += carry + '0';
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};