class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int top = 0, bot = n-1;
        int left = 0, right = n-1;
        int cnt = 1;
        
        while(top <= bot and left <= right)
        {
            for(int i=left;i<=right;i++)
                ans[top][i] = cnt++;
            top++;
            if(top > bot) break;
            
            for(int i=top;i<=bot;i++)
                ans[i][right] = cnt++;
            right--;
            if(left > right) break;
            
            for(int i=right;i>=left;i--)
                ans[bot][i] = cnt++;
            bot--;
            if(top > bot) break;
            
            for(int i=bot;i>=top;i--)
                ans[i][left] = cnt++;
            left++;
            if(left > right) break;
        }
        
        return ans;
    }
};