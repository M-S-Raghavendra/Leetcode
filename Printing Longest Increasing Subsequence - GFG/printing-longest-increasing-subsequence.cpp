//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1), par(n);
        vector<int> ans;
        int maxi = 0;
        int lastIndex = 0;
        
        for(int i=0;i<n;i++)
        {
            par[i] = i;
            for(int prev=0;prev<i;prev++)
            {
                if(arr[i] > arr[prev] and dp[prev]+1 > dp[i])
                {
                    dp[i] = dp[prev]+1;
                    par[i] = prev;
                }
            }
            if(maxi < dp[i])
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        int cur = lastIndex;
        while(par[cur] != cur)
        {
            ans.push_back(arr[cur]);
            cur = par[cur];
        }
        ans.push_back(arr[cur]);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends