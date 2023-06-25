//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
    
    int f(int i, int tar, int arr[], int n, vector<vector<int>> &dp)
    {
        if(i == n)
        {
            if(tar == 0) return 1;
            else return 0;
        }
        
        if(dp[i][tar] != -1) return dp[i][tar];
        
        int notpick, pick = 0;
        
        notpick = f(i+1,tar,arr,n,dp)%mod;
        if(arr[i] <= tar)
        {
            pick = f(i+1,tar-arr[i],arr,n,dp)%mod;
        }
        
        return dp[i][tar] = (notpick + pick)%mod;
    }
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(0,sum,arr,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends