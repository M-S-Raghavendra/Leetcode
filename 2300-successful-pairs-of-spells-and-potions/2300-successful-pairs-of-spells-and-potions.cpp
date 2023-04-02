class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());
        
        for(auto x:spells)
        {
            int index = bsearch(potions,x,success);
            
            if(index == -1)
                ans.push_back(0);
            else
                ans.push_back(m-index);
        }
        
        return ans;
    }
    
    int bsearch(vector<int> &p, int x, long long suc)
    {
        int s = 0, e = p.size()-1;
        int ans = -1;
        while(s <= e)
        {
            int m = s + (e-s)/2;
            
            if((long long)x*p[m] >= suc)
            {
                ans = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        
        return ans;
    }
};