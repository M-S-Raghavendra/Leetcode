class Solution {
public:
    int largestRectangleHistogram(vector<int> &h)
    {
        stack<int> s;   //store index
        int n = h.size();
        vector<int> leftSmall(n), rightSmall(n);
        vector<int> ans(n);
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and h[s.top()] >= h[i])
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
            while(!s.empty() and h[s.top()] >= h[i])
                s.pop();
            if(s.empty())
                rightSmall[i] = h.size() - 1;
            else
                rightSmall[i] = s.top() - 1;
            s.push(i);
            
            maxi = max(maxi, h[i]*(rightSmall[i] - leftSmall[i] + 1));
        }
        
        // cout<<maxi<<endl;
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            
            int tempAns = largestRectangleHistogram(heights);
            ans = max(ans,tempAns);
        }
        
        return ans;
    }
};