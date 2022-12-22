//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        // vector<vector<int>> dp(n,vector<int>(n+1,0));
        // return f(n-1,n,price,dp);
        vector<int> prev(n+1,0);
        
        for(int L=0;L<=n;L++)
            if(1 <= L) prev[L] = (L/1)*price[0];
            
        for(int ind = 1;ind<n;ind++)
        {
            for(int L = 0;L<=n;L++)
            {
                int nottake = prev[L];
                int take = INT_MIN;
                if(ind+1 <= L)
                    take = price[ind] + prev[L-(ind+1)];
                prev[L] = max(nottake,take);
            }
        }
        
        return prev[n];
    }
    
    int f(int ind, int L, int price[], vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            //ind+1 == 1, since ind == 0
            if(ind+1 <= L) return (L/(ind+1))*price[0];
            else return 0;
        }
        if(dp[ind][L] != -1) return dp[ind][L];
        
        int nottake = f(ind-1,L,price,dp);
        int take = INT_MIN;
        if(ind+1 <= L)
            take = price[ind] + f(ind,L-(ind+1),price,dp);
        return dp[ind][L] = max(nottake,take);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends