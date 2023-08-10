class Solution {
public:
    unordered_map<string,int> m;
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        
        return f(s1,s2);
    }
    
    bool f(string s1, string s2)
    {
        int n = s1.size();
        
        if(n == 0) return true;
        if(n == 1) return s1[0] == s2[0];
        
        string temp = s1;
        temp += " ";
        temp += s2;
        
        if(m.find(temp) != m.end())
            return m[temp];
        
        bool ans = false;
        for(int i=0;i<n-1;i++)
        {
            // Swapped case
            if(f(s1.substr(0,i+1), s2.substr(n-i-1)) and f(s1.substr(i+1), s2.substr(0,n-i)))
                ans |= true;
            
            // Not swapped case
            if(f(s1.substr(0,i+1), s2.substr(0,i+1)) and f(s1.substr(i+1), s2.substr(i+1)))
                ans |= true;
            
            if(ans)
                return true;
            
//             string l1 = s1.substr(i,k-i+1);
//             string l2 = s2.substr(i,k-i+1);
//             string r1 = s1.substr(k+1,j-k);
//             string r2 = s2.substr(k+1,j-k);
            
//             string r2cross = s2.substr(j-k);    // j-k == (j-i+1)-(k-i+1)
//             string l2cross = s2.substr(i,j-k);
//             cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
//             cout<<l2cross<<" "<<r2cross<<endl;
                        
            // if((l1 == l2 and r1 == r2) or (l1 == r2cross and r1 == l2cross))
            //     return true;
            // ans |= f(i,k,s1,s2) and f(k+1,j,s1,s2);
        }
        
        return m[temp] = ans;
    }
};