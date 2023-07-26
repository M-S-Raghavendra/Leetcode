class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = 0;
        int low = 1, high = 1e7;
        
        while(low <= high)
        {
            int m = (low + high)/2;
            if(canReach(dist,m,hour))
                high = m-1;
            else
                low = m+1;
        }
        if(low >1e7)
            return -1;
        
        return low;
    }
    
    bool canReach(vector<int> &dist, int m, double hour)
    {
        int n = dist.size();
        double time= 0;
        for(int i=0;i<n-1;i++)
            time += ceil(1.0 * dist[i]/(1.0 * m));
        time += 1.0 * dist[n-1] / m;
        
        return (time <= hour);
    }
};