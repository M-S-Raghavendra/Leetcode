//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    long long power(long long a, long long b, long long m)
    {
        long long ans = 1;
        
        for(int i=1;i<=b;i++)
        {
            ans = ans * a;
            if(ans > m) return 2;
        }
        if(ans == m) return 1;
        if(ans < m) return 0;
    }
    
	public:
	int NthRoot(int n, int m)
	{
	    long long s = 1, e = m;
	    
	    while(s <= e)
	    {
	        long long mid = s + (e-s)/2;
	        long long p = power(mid,n,m);
	        if(p == 1)
	            return mid;
	        else if(p == 0)
	            s = mid+1;
	        else
	            e = mid-1;
	    }
	    
	    return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends