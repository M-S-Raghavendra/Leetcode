class Solution {
public:    
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int k = 1;
        int j;
        
        for(j=0;j<n;j++)
        {
            if(nums[j] == 0) k--;
            if(k < 0)
            {
                if(nums[i] == 0)
                    k++;
                i++;
            }
        }
        
        return j-i-1;
        
//         int i = 0, j = 0, z = -1;
//         int ans = 0;
//         bool done;
        
//         while(i<n and j<n)
//         {
//             done = false;
//             while(j < n and nums[j] == 0)
//                 j++;
//             i = j;
            
//             while(j<n and nums[j] == 1)
//                 j++;
            
//             z = j;
//             if(j<n) 
//             {
//                 done = true;
//                 j++;
//             }
            
//             while(j<n and nums[j] == 1)
//                 j++;
            
//             if(i == 0 and j == n and z == n)
//                 done = true;
            
//             ans = max(ans, j-i-(done));
//             j = i = z+1;
//         }
        
//         return ans;
    }
};