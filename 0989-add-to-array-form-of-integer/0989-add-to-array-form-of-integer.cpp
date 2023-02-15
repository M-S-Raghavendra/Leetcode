class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i = n-1;
        int dig, sum, carry = 0;
        
        while(i >= 0 and k)
        {
            dig = k%10;
            sum = nums[i] + dig + carry;
            nums[i] = sum%10;
            carry = sum/10;
            i--;
            k /= 10;
        }
        
        while(i >= 0)
        {
            sum = nums[i] + carry;
            nums[i--] = sum%10;
            carry = sum/10;
        }
        
        while(k)
        {
            sum = k%10 + carry;
            nums.insert(nums.begin(),sum%10);
            carry = sum/10;
            k /= 10;
        }
        
        if(carry != 0)
            nums.insert(nums.begin(),carry);
        
        return nums;
    }
};