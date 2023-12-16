class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> m;
        long long ans = 0;
        
        for(auto x:rectangles)
        {
            if(m.find(1.0 * x[0]/x[1]) != m.end())
                ans += m[1.0 * x[0]/x[1]];
            m[1.0 * x[0]/x[1]]++;
        }
        
        return ans;
    }
};