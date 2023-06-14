class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;   //store index
        int n = heights.size();
        vector<int> leftSmall(n), rightSmall(n);
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = s.top() + 1;
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                rightSmall[i] = heights.size() - 1;
            else
                rightSmall[i] = s.top() - 1;
            s.push(i);
            
            maxi = max(maxi, heights[i]*(rightSmall[i] - leftSmall[i] + 1));
        }
        
        return maxi;
    }
};