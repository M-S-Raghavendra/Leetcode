class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin(),piles.end(),0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        int aliceScore = f(0,n-1,0,piles,dp);
        int bobScore = total - aliceScore;
        // cout<<aliceScore<<endl;
        return (aliceScore > bobScore);
    }
    
    int f(int i, int j, int turn, vector<int> &p, vector<vector<vector<int>>> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        
        if(turn == 0)   // Alice's turn
            return dp[i][j][turn] = max(p[i] + f(i+1,j,1,p,dp), p[j] + f(i,j-1,1,p,dp));
        else
            return dp[i][j][turn] = min(f(i+1,j,0,p,dp), f(i,j-1,0,p,dp));
    }
};