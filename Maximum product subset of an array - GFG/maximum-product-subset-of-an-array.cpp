//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        int z = 0;
        int neg = 0;
        int prevNeg = -1;
        long long ans = 1;
        int mod = 1e9+7;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] > 0)
            {
                ans = (ans * a[i]) % mod;
            }
            else if(a[i] < 0) 
            {
                ans = (ans * a[i]) % mod;
                if(prevNeg == -1 or a[prevNeg] < a[i])
                    prevNeg = i;
                neg++;
            }
            else
            {
                z++;
            }
        }
        
        if(z == n) return 0;
        
        if(ans < 0)
        {
            if(neg == 1 and z and neg+z == n) return 0;
            if(neg == 1 and neg == n) return ans;
            ans = (ans / a[prevNeg]) % mod;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends