class Solution {
private:
    int mod = 1e9 + 7;
    
    int power(long long a, long long b)
    {
        if(b == 0)
            return 1;
        long long temp = power(a,b/2) % mod;
        if(b%2 == 0)
            return (temp*temp) % mod;
        else
            return (((temp*temp)%mod) * a)%mod;
    }
    
public:
    int countGoodNumbers(long long n) {
        int ans = 0;
        long long even = ceil(n/2.0);
        long long prime = floor(n/2.0);
        
        // cout<<even<<" "<<prime<<endl;
        
        ans = (ans + power(5,even))%mod;
        if(prime != 0)
        {
            long long t =  power(4,prime)%mod;
            ans = (ans * t)%mod;
        }
        
        return ans;
    }
};