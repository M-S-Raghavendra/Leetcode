//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        int ans = 0;
        
        if(r-l < 4)
        {
            for(int i=l;i<=r;i++)
                ans ^= i;
        }
        else {
            while(l%4 != 0) ans ^= l++;
            while(r%4 != 0) ans ^= r--;
            ans ^= r;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends