class Solution {
public:
    // bool isprime(int n)
    // {
    //     for(int i=1;i*i<=n;i++)
    //     {
    //         if(n%i == 0)
    //             return false;
    //     }
    //     return true;
    // }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        
        if(n == 1)
            return (long long)time[0]*totalTrips;
        
        sort(time.begin(),time.end());
        long long s = 0, e = 1e12;
        long long ans = -1;
        
        while(s <= e)
        {
            long long m = s + (e-s)/2;
            long long cur = 0;
            
            for(auto x:time)
            {
                cur += (m/x);
            }
            // cout<<cur<<"\n";
            if(cur >= totalTrips)
            {
                ans = m;
                e = m-1;
            }
            else {
                s = m+1;
            }
        }
        
        return ans;
        
//         double d=0;
//         double t;
        
//         for(auto x:time)
//         {
//             d += ((double)1/(double)x);
//         }
        
//         t = (double)totalTrips/d;
        
//         long long ans = t;
        
//         cout<<d<<" "<<ans<<" "<<t;
        
//         if(ans==t)
//             return ans;
//         else
//             return ans+1;
        
//         int cnttrips=0;
//         int tm=0;
        
//         while(cnttrips < totalTrips)
//         {
//             tm++;
//             // if(isprime(tm) and tm!=1)
//             // {
//             //     if(find(time.begin(),time.end(),tm) != time.end())
//             //     {
//             //         cnttrips++;
//             //     }
//             //     if(find(time.begin(),time.end(),1) != time.end())
//             //     {
//             //         cnttrips++;
//             //     }
//             //     if(cnttrips >= totalTrips)
//             //         return tm;
//             //     continue;
//             // }
//             for(int i=0;i<time.size();i++)
//             {
//                 if(tm%time[i] == 0)
//                 {
//                     cnttrips++;
//                 }
//             }
//         }
        
//         return tm;
    }
};