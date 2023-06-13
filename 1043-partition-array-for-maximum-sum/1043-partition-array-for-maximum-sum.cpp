class Solution {
public:
    int f(int i, int k, vector<int> &arr, vector<int> &dp)
    {
        if(i == arr.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int len = 0, maxi = INT_MIN;
        int sum = 0;
        int maxAns = INT_MIN;
        int n = arr.size();
        
        for(int ind=i;ind<min(n,i+k);ind++)
        {
            len++;
            maxi = max(maxi,arr[ind]);
            sum = (len*maxi) + f(ind+1,k,arr,dp);
            maxAns = max(maxAns,sum);
        }
        
        return dp[i] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return f(0,k,arr,dp);
    }
};