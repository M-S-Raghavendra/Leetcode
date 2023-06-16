class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] > nums[(i+1)%n])
            {
                cnt++;
                if(cnt > 1)
                    return false;
            }
        }
        return true;
        
//         int index = -1;
//         int n = nums.size();
//         for(int i=1;i<n;i++)
//         {
//             if(nums[i] < nums[i-1]) {
//                 index = i;
//                 break;
//             }
//         }
        
//         if(index == -1)
//             return true;
//         reverse(nums.begin(),nums.begin()+index);
//         reverse(nums.begin()+index,nums.end());
//         reverse(nums.begin(),nums.end());
        
//         for(int i=1;i<n;i++)
//         {
//             if(nums[i] < nums[i-1])
//                 return false;
//         }
//         return true;
    }
};