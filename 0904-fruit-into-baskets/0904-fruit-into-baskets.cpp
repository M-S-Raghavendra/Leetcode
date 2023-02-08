class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        
        int i=0,j=0;
        unordered_map<int,int> m;
        int ans = INT_MIN;
        
        while(j < n)
        {
            m[f[j]]++;
            while(m.size() > 2)
            {
                if(m[f[i]] == 1)
                    m.erase(f[i]);
                else 
                    m[f[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};