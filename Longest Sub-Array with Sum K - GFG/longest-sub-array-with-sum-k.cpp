//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> m;
        int prefixSum = 0;
        int maxLen = 0;
        m[0] = -1;
        
        for(int i=0;i<N;i++)
        {
            prefixSum += A[i];


            if(m.find(prefixSum - K) != m.end()) 
            {
                maxLen = max(maxLen, i - m[prefixSum-K]);
            }
            if(m.find(prefixSum) == m.end())
                m[prefixSum] = i;
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends