class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        f(1,n,k,comb,ans);
        return ans;
    }
    
    void f(int i, int n, int k, vector<int> &comb, vector<vector<int>> &ans)
    {
        if(k == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        if(i > n) return;
        
        f(i+1,n,k,comb,ans);
        
        comb.push_back(i);
        f(i+1,n,k-1,comb,ans);
        comb.pop_back();
    }
};