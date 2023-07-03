class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() and dq.front() == i-k)
                dq.pop_front();
            while(!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
        
//         multiset<int> s;
        
//         for(int i=0;i<k;i++)
//             s.insert(nums[i]);
//         ans.push_back(*s.rbegin());
        
//         for(int i=k;i<n;i++)
//         {
//             s.erase(s.find(nums[i-k]));
//             s.insert(nums[i]);
//             ans.push_back(*s.rbegin());
//         }
//         return ans;
    }
};