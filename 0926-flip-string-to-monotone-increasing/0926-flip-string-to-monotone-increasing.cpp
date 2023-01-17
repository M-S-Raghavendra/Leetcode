class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        // vector<int> dp(n,-1);
        // return f(n-1,s,dp);
        
        int countOnes = 0, flips = 0;
        
        for(auto &x:s)
        {
            if(x == '1') 
                countOnes++;
            else
                flips++;            
            
            flips = min(flips,countOnes);
        }
        
        return flips;
    }
    
//     int f(int i, string &s, vector<int> &dp)
//     {
//         if(i < 0)
//         {
//             if(monotone(s))
//                 return 0;
//             else return 1e9;
//         }
        
//         if(dp[i] != -1) return dp[i];
        
//         int notflip = f(i-1,s,dp);
        
//         if(s[i] == '1') s[i] = '0';     //Flip
//         else s[i] = '1';
        
//         int flip = 1 + f(i-1,s,dp); 
//         if(s[i] == '1') s[i] = '0';     //Backtracking
//         else s[i] = '1';
        
//         int ans = min(flip,notflip);
//         if(ans < 1e9)
//             dp[i] = ans;
//         return ans;
//     }
    
//     bool monotone(string &s)
//     {
//         int i=0;
//         while(i < s.length() and s[i] == '0')
//             i++;
//         if(i == s.length()) return true;
//         while(i < s.length())
//         {
//             if(s[i] == '0')
//                 return false;
//             i++;
//         }
//         return true;
//     }
};