class Solution {
public:
    double soupServings(int n) {
        // Instead of n ml, consider no. of servings(each of 25 ml)
        // Ceil bcz, remaining serving(< 25ml) is also considered an individual serving
        
        // If n > 4800, then answer would be near 1(for 5 decimal places precision), bcz
        // there is no serving of A->0ml and B->100ml, so B's probability of
        // reaching 0 ireduces with increase in n (beyond 4800 ==> fact(by trial & error))
        if(n > 4800)
            return 1;
        
        vector<vector<double>> dp(200,vector<double>(200,-1));
        return f(ceil(1.0*n/25),ceil(1.0*n/25),dp);
    }
    
    double f(int a, int b, vector<vector<double>> &dp)
    {
        if(a <= 0 and b > 0)
            return 1;
        if(a <= 0 and b <= 0)
            return 0.5;
        if(b <= 0)
            return 0;
        
        if(dp[a][b] != -1) return dp[a][b];
        
        double s1 = f(a-4,b,dp);
        double s2 = f(a-3,b-1,dp);
        double s3 = f(a-2,b-2,dp);
        double s4 = f(a-1,b-3,dp);
        
        return dp[a][b] = 0.25 * (s1+s2+s3+s4);
    }
};