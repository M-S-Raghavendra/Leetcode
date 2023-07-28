class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        int p1 = f(0,n-1,0,nums,dp);
        int p2 = total - p1;
        // cout<<p1<<endl;
        return p1 >= p2;
    }
    
    int f(int i, int j, int turn, vector<int> &nums, vector<vector<vector<int>>> &dp)
    {
        if(i > j)
            return 0;
        // cout<<i<<" "<<j<<" "<<turn<<endl;
        
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        
        if(turn == 0)
            return dp[i][j][turn] = max(nums[i] + f(i+1,j,1,nums,dp), nums[j] + f(i,j-1,1,nums,dp));
        else
            return dp[i][j][turn] = min(f(i+1,j,0,nums,dp), f(i,j-1,0,nums,dp));
    }
};