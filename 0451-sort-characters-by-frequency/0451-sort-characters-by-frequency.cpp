class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        for(auto x:s)
            m[x]++;
        for(auto x:m)
            pq.push({x.second,x.first});
        
        string ans = "";
        while(!pq.empty())
        {
            auto x = pq.top(); pq.pop();
            for(int i=0;i<x.first;i++)
                ans += x.second;
        }
        return ans;
    }
};