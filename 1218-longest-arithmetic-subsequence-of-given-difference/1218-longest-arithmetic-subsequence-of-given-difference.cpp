class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> m;
        int ans = 0;
        
        for(auto x:arr)
        {
            if(m.find(x-difference) != m.end())
                m[x] = 1 + m[x-difference];
            else
                m[x] = 1;
            
            ans = max(ans, m[x]);
        }
        
        return ans;
        
//         multiset<pair<int,int>> s;
//         for(int i=0;i<n;i++)
//             s.insert({arr[i],i});
//         int d = difference;
//         int ans = 0;
        
//         for(int i=0;i<n;i++)
//         {
//             if(s.find({arr[i]-d,_}) == s.end())
//             {
//                 int x = arr[i];
//                 int cnt = 1;
//                 int ind = 
//                 while(s.find(x+d) != s.end())
//                 {
//                     cnt++;
//                     x += d;
//                 }
//                 ans = max(ans,cnt);
//             }
//         }
        
//         return ans;
        
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(0,-1,difference,arr,dp);
    }
    
    int f(int i, int p, int d, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(i == arr.size())
            return 0;
        
        if(dp[i][p+1] != -1) return dp[i][p+1];
        
        int notpick = 0 + f(i+1,p,d,arr,dp);
        int pick = 0;
        if(p == -1 or (arr[i]-arr[p]) == d)
            pick = 1 + f(i+1,i,d,arr,dp);
        
        return dp[i][p+1] = max(notpick, pick);
    }
};