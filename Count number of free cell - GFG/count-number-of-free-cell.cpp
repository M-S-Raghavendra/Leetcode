//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int N, int k, vector<vector<int>>& arr){
      unordered_set<int> row, col;
      vector<long long int> ans;
      long long int ones = 0;
      
      for(int i=0;i<k;i++)
      {
          int r = arr[i][0]-1;
          int c = arr[i][1]-1;
          bool rn = false, cn = false;
          
          if(row.find(r) == row.end())
          {
              ones += (N-col.size());
              rn = true;
          }
          if(col.find(c) == col.end())
          {
              ones += (N-row.size());
              cn = true;
          }
          
          if(rn or cn)
          {
              row.insert(r);
              col.insert(c);
          }
          
          if(rn and cn)
            ones--;
        
          ans.push_back(N*N-ones);
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends