//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<int> s;
    
    bool isPrime(int d) {
        return s[d];
    }
        
  public:
    void sieve() {
        for(int i=2;i<s.size();i++)
        {
            if(s[i] == 1) {
                for(long long int j=i*i;j<s.size();j+=i)
                    s[j] = 0;
            }
        }
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> ans;
        s.resize(N+1,1);
        sieve();
        int d = 2;
        
        while(N and d <= N)
        {
            if(isPrime(d)) {
                while(N and N%d == 0)
                {
                    ans.push_back(d);
                    N /= d;
                }
            }
            d++;
        }
        
        return ans;
        
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends