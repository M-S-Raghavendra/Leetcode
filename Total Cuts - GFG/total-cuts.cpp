//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> mx(N), mn(N);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int ans = 0;
        
        for(int i=0;i<N;i++)
        {
            maxi = max(maxi,A[i]);
            mx[i] = maxi;
        }
        for(int i=N-1;i>=0;i--)
        {
            mini = min(mini,A[i]);
            mn[i] = mini;
        }
            
        for(int i=0;i<N-1;i++)
        {
            if(mx[i] + mn[i+1] >= K)
                ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends