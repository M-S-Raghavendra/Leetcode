//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int k, vector<long long> GeekNum) {
        long long ans = 0;
        long long cnt = k, sum = 0;
        
        if(N <= k)
            return GeekNum[N-1];
        
        for(int i=0;i<k;i++)
            sum += GeekNum[i];
        
        while(cnt != N-1)
        {
            GeekNum.push_back(sum);
            sum += GeekNum.back();
            sum -= GeekNum[cnt-k];
            cnt++;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends