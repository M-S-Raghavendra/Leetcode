class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res1=nums[0];
        int maxEnding1=nums[0];
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum += nums[i];
        
        for(int i=1;i<n;i++)
        {
            maxEnding1 = max(maxEnding1+nums[i], nums[i]);
            res1 = max(res1,maxEnding1);
        }
        
        int res2=nums[0];
        int maxEnding2=nums[0];
        
        for(int i=1;i<n;i++)
        {
            maxEnding2 = min(maxEnding2+nums[i], nums[i]);
            res2 = min(res2,maxEnding2);
        }
        
        int cres = sum - res2;
        if(cres == 0)
            return res1;
        
        return max(res1,cres);
        
//         for(int i=0;i<n;i++)
//         {
//             int cur=nums[i];
//             res = max(res,cur);
            
//             for(int j=1;j<n;j++)
//             {
//                 int index = (i+j)%n;
                
//                 cur += nums[index];
//                 res = max(res,cur);
//             }
//         }
        return cres;
    }
};