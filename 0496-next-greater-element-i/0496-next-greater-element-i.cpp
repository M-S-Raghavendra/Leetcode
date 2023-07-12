class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;
        stack<int> s;
        
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!s.empty() and nums2[i] >= s.top())
                s.pop();
            if(s.empty())
                nextGreater[nums2[i]] = -1;
            else
                nextGreater[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for(auto x:nums1)
            ans.push_back(nextGreater[x]);
        return ans;
    }
};