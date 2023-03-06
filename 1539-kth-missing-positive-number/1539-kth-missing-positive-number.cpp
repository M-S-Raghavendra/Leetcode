class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s;
        for(auto x:arr)
            s.insert(x);
        int cnt = 1;
        int i = 1;
        
        while(1)
        {
            if(s.find(i) == s.end())
            {
                if(k == cnt)
                    return i;
                else
                    cnt++;
            }
            i++;
        }
        
        return -1;
    }
};