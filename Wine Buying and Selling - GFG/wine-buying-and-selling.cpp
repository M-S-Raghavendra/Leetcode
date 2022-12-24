//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      int s = 0, e = 0;
      long long ans = 0;
      
      while(s<n and e<n)
      {
          while(s<n and arr[s] <= 0) s++;
          while(e<n and arr[e] >= 0) e++;
          
          if(s>=n or e>=n) break;
          long long int diff = abs((e-s));
          
          if(arr[s] > abs(arr[e]))
          {
              ans += diff*abs(arr[e]);
              arr[s] -= abs(arr[e]);
              arr[e] = 0;
          }
          else if(arr[s] <= abs(arr[e])) {
              ans += diff*arr[s];
              arr[e] += arr[s];
              arr[s] = 0;
          }
        //   cout<<ans<<" ";
      }
      
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends