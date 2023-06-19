class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefixSum = 0;
        int maxAl = 0;
        
        for(auto x:gain)        
        {
            prefixSum += x;
            maxAl = max(maxAl,prefixSum);
        }
        
        return maxAl;
    }
};