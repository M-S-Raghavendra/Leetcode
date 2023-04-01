class Solution {
private:
    vector<bool> prime;
    
    void seive()
    {
        for(int i=2;i<=1000;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=1000;j+=i)
                    prime[j] = false;
            }
        }
    }
    
public:
    bool primeSubOperation(vector<int>& nums) {
        prime.resize(1001,true);
        seive();
        
        int n = nums.size();
        
        int cnt = 0;
        for(int i=0;i<n-1;i++)
            if(nums[i] < nums[i+1])
                cnt++;
        
        if(cnt == n-1)
            return true;
        
        for(int i=0;i<n;i++)
        {
            int prm = -1;
            
            for(int j = nums[i]-1;j>=2;j--)
                if(prime[j] and (i == 0 or (nums[i]-j) > nums[i-1]))
                {
                    prm = j;
                    break;
                }
            
            if(prm == -1 and i != 0)
            {
                if(nums[i] <= nums[i-1])
                    return false;
                else
                    prm = 0;
            }
            
            nums[i] -= prm;
        }
        
        return true;
    }
};