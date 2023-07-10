class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        
        // O(sqrt(n))
        for(int i=1;i*i<=n;i++)
        {
            if(n % i == 0)
                cnt++;
        }
        
        int size = 2*cnt;
        double y = sqrt(1.0 * n);
        int x = sqrt(n);
        
        if(x == y)
            size--;
        int ind = 0;
        for(int i=1;i*i<=n;i++)
        {
            if(n % i == 0)
            {
                ind++;
                if(ind == k)
                    return i;
                if(size-ind+1 == k)
                    return n/i;
            }
        }
        
        return -1;
        
//         O(n)
//         for(int i=1;i<=n;i++)
//         {
//             if(n % i == 0)
//             {
//                 cnt++;
//                 if(cnt == k)
//                     return i;
//             }
//         }
        
//         return -1; 
    }
};