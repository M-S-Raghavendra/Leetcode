//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        stack<int> s;
        
        for(long long int i=1;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                cout<<i<<" ";
                if(i*i != n)
                    s.push(n/i);
            }
        }

        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends