class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nextGE(n), prevGE(n);
        int ans = 0;
        prevGE[0] = 0;
        nextGE[n-1] = n-1;
        
        for(int i=1;i<n;i++)
        {
            if(height[i] > height[prevGE[i-1]])
                prevGE[i] = i;
            else
                prevGE[i] = prevGE[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(height[i] > height[nextGE[i+1]])
                nextGE[i] = i;
            else
                nextGE[i] = nextGE[i+1];
            
            ans += min(height[prevGE[i]], height[nextGE[i]]) - height[i];
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<prevGE[i]<<" ";
        //     cout<<nextGE[i]<<endl;
        // }
        
        return ans;
    }
};