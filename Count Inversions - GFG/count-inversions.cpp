//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr,0,N-1);
    }
    
    long long int mergesort(long long arr[], int l, int r)
    {
        long long int cnt = 0;
        if(l < r)
        {
            int m = (l+r)/2;
            cnt += mergesort(arr,l,m);
            cnt += mergesort(arr,m+1,r);
            cnt += merge(arr,l,m,r);
        }
        return cnt;
    }
    
    long long int merge(long long arr[], int l, int m, int r)
    {
        int n1 = m-l+1, n2 = r-m;
        long long left[n1], right[n2];
        long long int cnt = 0;
        
        for(int i=0;i<n1;i++)
            left[i] = arr[l+i];
        for(int i=0;i<n2;i++)
            right[i] = arr[m+1+i];
        
        int i = 0, j = 0, k = l;
        while(i < n1 and j < n2)
        {
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else 
            {
                arr[k++] = right[j++];
                cnt += n1-i;
            }
        }
        
        while(i < n1)
            arr[k++] = left[i++];
        while(j < n2)
            arr[k++] = right[j++];
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends