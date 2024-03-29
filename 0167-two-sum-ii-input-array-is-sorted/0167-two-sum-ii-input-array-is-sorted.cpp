class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n-1;
        int sum;
        
        while(i < j)
        {
            sum = numbers[i] + numbers[j];
            if(sum == target)
                return {i+1,j+1};
            else if(sum < target)
                i++;
            else
                j--;
        }
        
        return {0,0};
    }
};