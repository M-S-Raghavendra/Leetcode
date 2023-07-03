class Solution {
public:
    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = l;
        int i = l;
        int j = r;
        
        while(1)
        {
            while(i <= j and nums[i] <= nums[pivot])
                i++;
            while(i <= j and nums[j] > nums[pivot])
                j--;
            if(i < j)
                swap(nums[i],nums[j]);
            else {
                swap(nums[pivot],nums[j]);
                return j;
            }
        }
        
        return 0;
    }
    
    int quickSort(vector<int> &nums, int l, int r, int k)
    {
        int n = nums.size();
        if(l <= r)
        {
            int s = partition(nums,l,r);
            if(s == n-k)
                return nums[s];
            else if(s > n-k)
                return quickSort(nums,l,s-1,k);
            else
                return quickSort(nums,s+1,r,k);
        }
        return 0;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // Using Quixk sort PARTITION approach
        return quickSort(nums,0,nums.size()-1,k);
        
//         priority_queue<int,vector<int>,greater<int>> pq;
        
//         for(auto x:nums)
//         {
//             pq.push(x);
//             if(pq.size() > k)
//                 pq.pop();
//         }
        
//         return pq.top();
    }
};