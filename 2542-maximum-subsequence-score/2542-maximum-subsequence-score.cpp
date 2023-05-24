class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();i++)
            v.push_back({nums2[i],nums1[i]});
        
        sort(v.rbegin(),v.rend());
        
        priority_queue<int,vector<int>,greater<int>> pq;    //min heap
        long long sum = 0;
        
        for(auto x:v)
        {
            sum += x.second;
            pq.push(x.second);
            
            if(pq.size() > k)
            {
                sum -= pq.top();    //remove min element
                pq.pop();           //remove min element
            }
            if(pq.size() == k)
                ans = max(ans, sum * x.first);  // x.first is minimum, bcz sorted in desc order
        }
        
        return ans;
    }
};