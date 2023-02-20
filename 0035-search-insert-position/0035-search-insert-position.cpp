class Solution {
private:
    int binarySearch(vector<int>& nums, int key) {
        int n = nums.size();
        int s=0;
        int e=n-1;
        int mid;
        
        while(s<=e)
        {
            mid = s + (e - s)/2;
            if(nums[mid] == key)
                return mid;
            if(nums[mid] > key)
                e = mid-1;
            else
                s = mid+1;
        }
        
        if(key < nums[mid])
            return mid;
        else
            return mid+1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
};