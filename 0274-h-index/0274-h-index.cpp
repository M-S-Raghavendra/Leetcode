class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int ans = n;
        
        for(int i=n-1;i>=0;i--)
        {
            if(citations[n-ans] >= ans)
                return ans;
            ans--;
        }
        
        return ans;            
    }
};