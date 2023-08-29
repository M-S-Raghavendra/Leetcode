class Solution {
public:
    int bestClosingTime(string customers) {
        int prevNo = 0, afterYes = 0;
        for(auto x:customers)
            if(x == 'N')
                prevNo++;
        
        int n = customers.size();
        int minPenalty = n;
        int ans = n;
        
        for(int i=n-1;i>=-1;i--)
        {
            if(prevNo + afterYes <= minPenalty)
            {
                minPenalty = prevNo + afterYes;
                ans = i;
            }
            if(i == -1) continue;
            if(customers[i] == 'Y')
                afterYes++;
            else
                prevNo--;
        }
        
        return ans+1;
    }
};