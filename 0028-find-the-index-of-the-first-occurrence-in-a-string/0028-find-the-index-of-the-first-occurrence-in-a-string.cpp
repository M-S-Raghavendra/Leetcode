class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ind = haystack.find(needle);
        if(ind == string::npos)
            return -1;
        return ind;
    }
};