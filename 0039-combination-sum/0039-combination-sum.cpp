class Solution {
public:
    void f(int i, int tar, vector<int> &c, vector<int> &s, vector<vector<int>> &ans)
    {
        if(tar == 0)
        {
            ans.push_back(s);
            return ;
        }
        
        if(i == c.size())
        {
            if(tar == 0)
            {
                ans.push_back(s);
            }
            return ;
        }
        
        //pick
        if(c[i] <= tar)
        {
            s.push_back(c[i]);
            f(i,tar-c[i],c,s,ans);
            s.pop_back();
        }
        
        // not pick
        f(i+1,tar,c,s,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> s;
        
        f(0,target,candidates,s,ans);
        return ans;
    }
};