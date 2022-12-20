class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;        
        for(int i=0;i<s.size()/2;i++)
            if(isVowel(s[i]))
                cnt++;
        for(int i=s.size()/2;i<s.size();i++)
            if(isVowel(s[i]))
                cnt--;
           
        return (cnt == 0);
    }
    
    bool isVowel(char c)
    {
        if(c == 'a' or c=='e' or c=='i' or c=='o' or c=='u')
            return true;
        if(c=='A' or c=='E' or c=='I' or c=='O' or c=='U') 
            return true;
        return false;
    }
};