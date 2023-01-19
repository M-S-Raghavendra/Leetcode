class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> m;
        int ans = 0;
        int N = 1e9 + 7;
        
        for(auto x:deliciousness)
        {
            for(int i=0;i<=21;i++)
            {
                int req = (1<<i) - x;
                if(m.find(req) != m.end())
                    ans = (ans + m[req])%N;
            }
            m[x]++;
        }
        
        return (ans)%N;
    }
};