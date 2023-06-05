class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int denominator = coordinates[1][0] - coordinates[0][0];
        double slope;
        if(denominator != 0)
        {
            slope = (1.0)*(coordinates[1][1] - coordinates[0][1])
                            /(coordinates[1][0] - coordinates[0][0]);
        }
        double curm;
        
        for(int i=1;i<n-1;i++)
        {
            if(denominator == 0)
            {
                int tempd = coordinates[i+1][0] - coordinates[i][0];
                if(tempd != 0)
                    return false;
                continue;
            }
            curm = (1.0)*(coordinates[i+1][1] - coordinates[i][1])
                            /(coordinates[i+1][0] - coordinates[i][0]);
            if(curm != slope)
                return false;
        }
        
        return true;        
    }
};