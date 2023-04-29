class Solution {
public:
    int addDigits(int num) {
        while(len(num) > 1)
        {
            int sum = 0;
            int temp = num;
            while(temp)
            {
                sum += temp%10;
                temp /= 10;
            }
            num = sum;
        }
        
        return num;
    }
    
    int len(int n)
    {
        return to_string(n).length();
    }
};