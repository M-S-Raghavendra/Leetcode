class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int maxi = 0;
        
        for(auto x:s)
        {
            if(s.find(x-1) == s.end())
            {
                int num = x;
                int cnt = 1;
                while(s.find(num+1) != s.end())
                {
                    num++;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};