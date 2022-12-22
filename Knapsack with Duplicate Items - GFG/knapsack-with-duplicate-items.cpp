//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> dp(N,vector<int>(W+1,INT_MIN));
        // return f(N-1,W,wt,val,N,dp);
        
        vector<int> prev(W+1,0);
        
        for(int i=0;i<=W;i++)
        {
            if(wt[0] <= i) prev[i] = (i/wt[0])*val[0];
            else prev[i] = 0;
        }
        
        for(int ind=1;ind<N;ind++)
        {
            for(int w=0;w<=W;w++)
            {
                int nottake = 0 + prev[w];
                int take = INT_MIN;
                if(wt[ind] <= w)
                    take = val[ind] + prev[w-wt[ind]];
                prev[w] = max(nottake,take);
            }
        }
        
        return prev[W];
    }
    
    int f(int ind, int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(wt[0] <= W) return (W/wt[0])*val[0];
            else return 0;
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int nottake = 0 + f(ind-1,W,wt,val,n,dp);
        int take = INT_MIN;
        if(wt[ind] <= W)
            take = val[ind] + f(ind,W-wt[ind],wt,val,n,dp);
        return dp[ind][W] = max(nottake,take);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends