//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xr = 0, a = 0, b = 0;
        vector<int> ans(2);
        
        for(auto x:arr)
            xr ^= x;
        for(int i=1;i<=n;i++)
            xr ^= i;
        
        int rightSetBit = xr & ~(xr-1);
        for(auto x:arr)
        {
            if(x&rightSetBit)
                a ^= x;
            else
                b ^= x;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(i&rightSetBit)
                a ^= i;
            else
                b ^= i;
        }
        
        for(auto x:arr)
        {
            if(x == a)
            {
                ans[0] = a;
                ans[1] = b;
                break;
            }
            else if(x == b) {
                ans[0] = b;
                ans[1] = a;
                break;
            }
        }
        
        return ans;
    }

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends