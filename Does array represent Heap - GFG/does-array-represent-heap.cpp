//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            int leftChild = 2*i+1;
            int rightChild = 2*i+2;
            if((leftChild < n and arr[leftChild] > arr[i]) or 
                (rightChild < n and arr[rightChild] > arr[i])) {
                    return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends