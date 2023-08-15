class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0;
        long long temp = x;
        
        while(temp) {
            long long d = temp%10;
            rev = rev*10 + d;
            temp /= 10;
        }
        
        return x==rev;
    }
};