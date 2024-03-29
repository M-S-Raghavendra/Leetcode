//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum = 0;
        f(0,sum,arr,N,ans);
        return ans;
    }
    
    void f(int i, int sum, vector<int> &arr, int n, vector<int> &ans)
    {
        if(i == n)
        {
            ans.push_back(sum);
            return ;
        }
        
        // not pick
        f(i+1,sum,arr,n,ans);
        // pick
        f(i+1,sum+arr[i],arr,n,ans);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends