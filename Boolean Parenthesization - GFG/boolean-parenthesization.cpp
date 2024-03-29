//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    
    int f(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp)
    {
        // base case 1
        if(i > j)
            return 0;
        
        // base case 2
        if(i == j) {
            if(isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ways = 0;
        
        for(int ind=i+1;ind<=j-1;ind+=2)
        {
            int lt = f(i,ind-1,1,s,dp);
            int lf = f(i,ind-1,0,s,dp);
            int rt = f(ind+1,j,1,s,dp);
            int rf = f(ind+1,j,0,s,dp);
            
            if(s[ind] == '&') {
                if(isTrue)
                    ways = (ways + (lt*rt)%mod)%mod;
                else
                    ways = (ways + (lf*rt)%mod + (lt*rf)%mod + (lf*rf)%mod)%mod;
            }
            else if(s[ind] == '|') {
                if(isTrue)
                    ways = (ways + (lf*rt)%mod + (lt*rf)%mod + (lt*rt)%mod)%mod;
                else
                    ways = (ways + (lf*rf)%mod)%mod;
            }
            else {
                if(isTrue)
                    ways = (ways + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else
                    ways = (ways + (lt*rt)%mod + (lf*rf)%mod)%mod;
            }
        }
        
        return dp[i][j][isTrue] =  ways;
    }
    
    int countWays(int N, string s){
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N,vector<int>(2,0)));
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                for(int isTrue=0;isTrue<=1;isTrue++)
                {
                    if(i > j)
                        continue;
                    if(i == j) {
                        if(isTrue) dp[i][j][isTrue] = (s[i] == 'T');
                        else dp[i][j][isTrue] = (s[i] == 'F');
                        continue;
                    }
                    
                    int ways = 0;
                    for(int ind=i+1;ind<=j-1;ind+=2)
                    {
                        int lt = dp[i][ind-1][1];
                        int lf = dp[i][ind-1][0];
                        int rt = dp[ind+1][j][1];
                        int rf = dp[ind+1][j][0];
                        
                        if(s[ind] == '&') {
                            if(isTrue)
                                ways = (ways + (lt*rt)%mod)%mod;
                            else
                                ways = (ways + (lf*rt)%mod + (lt*rf)%mod + (lf*rf)%mod)%mod;
                        }
                        else if(s[ind] == '|') {
                            if(isTrue)
                                ways = (ways + (lf*rt)%mod + (lt*rf)%mod + (lt*rt)%mod)%mod;
                            else
                                ways = (ways + (lf*rf)%mod)%mod;
                        }
                        else {
                            if(isTrue)
                                ways = (ways + (lt*rf)%mod + (lf*rt)%mod)%mod;
                            else
                                ways = (ways + (lt*rt)%mod + (lf*rf)%mod)%mod;
                        }
                    }
                    
                    dp[i][j][isTrue] =  ways;
                }
            }
        }
        
        return dp[0][N-1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends