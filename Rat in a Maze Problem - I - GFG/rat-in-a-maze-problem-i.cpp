//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s = "";
        
        if(m[0][0] == 0 or m[n-1][n-1] == 0)
            return ans;
        
        f(0,0,m,s,ans,n);
        
        return ans;
    }
    
    void f(int i, int j, vector<vector<int>> &m, string &s, vector<string> &ans, int n)
    {
        if(i<0 or j<0 or i>=n or j>=n or m[i][j] == 0)
            return;
        
        if(i == n-1 and j == n-1)
        {
            ans.push_back(s);
            return;
        }
        
        // Up
        s += "U";
        m[i][j] = 0;
        f(i-1,j,m,s,ans,n);
        m[i][j] = 1;
        s.pop_back();
        
        // Down
        s += "D";
        m[i][j] = 0;
        f(i+1,j,m,s,ans,n);
        m[i][j] = 1;
        s.pop_back();
        
        // Left
        s += "L";
        m[i][j] = 0;
        f(i,j-1,m,s,ans,n);
        m[i][j] = 1;
        s.pop_back();
        
        // Right
        s += "R";
        m[i][j] = 0;
        f(i,j+1,m,s,ans,n);
        m[i][j] = 1;
        s.pop_back();
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends