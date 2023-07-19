//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int i, int j, vector<vector<int>> &mat, int n, int m, vector<vector<int>> &dp)
    {
        if(i < 0 or j < 0 or i >= n or j >= m)
            return 0;
            
        if(dp[i][j] != -1) return dp[i][j];
        
        int ud = f(i-1,j+1,mat,n,m,dp);
        int r = f(i,j+1,mat,n,m,dp);
        int dd = f(i+1,j+1,mat,n,m,dp);
        
        return dp[i][j] = mat[i][j] + max(ud,max(r,dd));
    }

public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
         vector<vector<int>> dp(n,vector<int>(m,-1));
         int maxi = -1;
         for(int i=0;i<n;i++)
         {
             maxi = max(maxi, f(i,0,M,n,m,dp));
         }
         
         return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends