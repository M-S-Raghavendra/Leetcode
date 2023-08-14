//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int m, int n, int k)
    {
        // Binary search logic
        if(m > n) return kthElement(nums2,nums1,n,m,k);
        
        int low = max(0, k-n), high = min(k,m);
        int left = k;
        int size = n+m;
        
        while(low <= high)
        {
            int mid1 = (low + high)/2;
            int mid2 = left - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            
            if(l1 <= r2 and l2 <= r1) {
                return max(l1,l2);
            }
            else if(l1 > r2)
                high = mid1 - 1;
            else if(l2 > r1)
                low = mid1 + 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends