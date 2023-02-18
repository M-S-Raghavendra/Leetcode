//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>> dp(N,vector<long long int>(4,-1));
        long long int ans = f(N-1,0,r,g,b,dp);
        return ans;
    }
    
    long long int f(int ind, int c, int r[], int g[], int b[], vector<vector<long long int>> &dp)
    {
        if(ind < 0)
            return 0;
        
        if(dp[ind][c] != -1) return dp[ind][c];
        
        long long int red, green, blue;
        red = green = blue = 1e16;
        if(c != 1)
            red = r[ind] + f(ind-1,1,r,g,b,dp);
        if(c != 2)
            green = g[ind] + f(ind-1,2,r,g,b,dp);
        if(c != 3)
            blue = b[ind] + f(ind-1,3,r,g,b,dp);
            
        return dp[ind][c] = min(red, min(green,blue));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends