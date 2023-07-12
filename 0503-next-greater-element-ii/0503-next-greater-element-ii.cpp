class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        queue<int> q;
        vector<int> ans(n);
        // for(int i=0;i<n;i++)
        //     nums.push_back(nums[i]);
        
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() and nums[i%n] >= s.top())
                s.pop();
            if(i < n)
            {
                if(s.empty())
                    ans[i] = -1;
                else
                    ans[i] = s.top();
            }
            s.push(nums[i%n]);
        }
        
        return ans;
    }
};