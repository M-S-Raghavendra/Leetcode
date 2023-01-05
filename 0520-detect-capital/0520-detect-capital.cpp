class Solution {
public:
    bool detectCapitalUse(string word) {
        int l=word.length();
        int cap=0, small=0;
        
        for(int i=0;i<l;i++)
        {
            if(word[i]>='a' and word[i]<='z')
                small++;
            if(word[i]>='A' and word[i]<='Z')
                cap++;
        }
        if(small==l)
            return true;
        if(cap==l)
            return true;
        
        if(cap > 1)
            return false;
        if(word[0] >= 'A' and word[0] <= 'Z')
            return true;
        return false;
        
//         int t=0;
        
//         if(word[0]>='A' and word[0]<='Z')
//             for(int i=1;i<l;i++)
//             {
//                 if(word[i]>='a' and word[i]<='z')
//                     t++;
//             }
//         if(t==l-1)
//             return true;
        
//         return false;
    }
};