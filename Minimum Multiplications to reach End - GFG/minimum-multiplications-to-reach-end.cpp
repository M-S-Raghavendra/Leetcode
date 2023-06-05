//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int N = 100000;
        // {steps,num}
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> vis(N,0);
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int num = it.second;
            
            if(num == end)
                return steps;
            
            for(auto x:arr)
            {
                int newNum = (num * x) % N;
                if(!vis[newNum])
                {
                    vis[newNum] = 1;
                    q.push({steps+1,newNum});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends