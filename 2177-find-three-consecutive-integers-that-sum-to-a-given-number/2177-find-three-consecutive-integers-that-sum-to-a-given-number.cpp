class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        
        long long s = -1, e = num;
        
        while(s <= e)
        {
            long long m = s + (e-s)/2;
            long long sum = m-1 + m + m+1;
            if(sum == num)
                return {m-1,m,m+1};
            else if(sum < num)
                s = m+1;
            else
                e = m-1;
        }
        
        return {};
    }
};