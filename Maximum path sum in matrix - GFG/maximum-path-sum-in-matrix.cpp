//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int ans = 0;
        
        for(int i=0;i<N;i++)
        {
            dp.resize(N,vector<int>(N,-1));
            ans = max(ans, f(0,i,Matrix));
        }
        
        return ans;
    }
    
    int f(int i, int j, vector<vector<int>> &mat)
    {
        if(j < 0 or j >= mat.size())
            return -1;
        if(i == mat.size()-1)
            return mat[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int dl = f(i+1,j-1,mat);
        int d = f(i+1,j,mat);
        int dr = f(i+1,j+1,mat);
        
        return dp[i][j] = max(dl,max(d,dr)) + mat[i][j];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends