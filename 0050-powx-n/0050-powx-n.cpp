class Solution {
public:
    double findPow(double x, long long n)
    {
        if(n == 0)
            return 1;

        double ans = myPow(x, n/2);
        ans *= ans;
        
        if(n%2 == 1)
            ans *= x;
        
        return ans;
    }
    
    double myPow(double x, int n) {
       double ans; 
          
       if(n < 0)
           ans = 1/findPow(x,(long long)(-1)*n);
       else
           ans = findPow(x,n);
            
        
        return ans;
    }
};