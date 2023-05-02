//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
    
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
            
        vector<pair<int,int>> v;
        
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends