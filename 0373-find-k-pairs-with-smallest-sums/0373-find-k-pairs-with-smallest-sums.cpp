class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k)
                    pq.push({sum,{nums1[i],nums2[j]}});
                else {
                    auto p = pq.top();
                    if(p.first <= nums1[i]+nums2[j])
                        break;
                    else {
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                }
            }
        }
        
        while(!pq.empty())
        {
            auto x = pq.top();
            ans.push_back({x.second.first,x.second.second});
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};