class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto x:tasks)
            m[x]++;
        int ans = 0;
        for(auto x:m)
        {
            int freq = x.second;
            if(freq == 1)
                return -1;
            ans += (freq + 2)/3;
            // if(freq%3 == 0)
            //     ans += freq/3;
            // else if(freq%3 == 1)
            // {
            //     ans += (freq/3) - 1;
            //     ans += 2;
            // }
            // else if(freq%3 == 2)
            // {
            //     ans += freq/3;
            //     ans += 1;
            // }
        }
        
        return ans;
    }
};