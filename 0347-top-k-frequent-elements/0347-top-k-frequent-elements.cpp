class Solution {
public:
    typedef pair<int,int> pi;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        unordered_map<int,int> m;        
        for(auto x:nums)
            m[x]++;
        
        for(auto x:m)
        {
            if(pq.size() < k)
                pq.push({x.second,x.first});
            else {
                if(x.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({x.second,x.first});
                }
            }
        }
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};